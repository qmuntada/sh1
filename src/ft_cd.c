/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:44:25 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 16:49:47 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void			change_pwd(t_lenv **env)
{
	t_lenv		*tmp;

	tmp = get_lenv(*env, "PWD");
	if (tmp == NULL)
		return ;
	tmp->value = getcwd(ft_strnew(1024), 1024);
}

void			cd_home(t_lenv **env)
{
	t_lenv		*tmp1;
	t_lenv		*tmp2;

	tmp1 = get_lenv(*env, "PWD");
	tmp2 = get_lenv(*env, "HOME");
	if (tmp1 && tmp1->value && tmp2 && tmp2->value &&
		access(tmp2->value, R_OK) == 0)
	{
		free(tmp1->value);
		tmp1->value = ft_strdup(tmp2->value);
		change_oldpwd(env);
		chdir(tmp1->value);
	}
	else
		ft_putendl("cd: incorrect or unassigned home path");
}

void			cd_env(t_lenv **env, char *path)
{
	t_lenv		*tmp1;
	t_lenv		*tmp2;

	tmp1 = get_lenv(*env, "PWD");
	tmp2 = get_lenv(*env, path + 1);
	if (tmp1 && tmp1->value && tmp2 && tmp2->value &&
	access(tmp2->value, R_OK) == 0)
	{
		free(tmp1->value);
		tmp1->value = ft_strdup(tmp2->value);
		change_oldpwd(env);
		chdir(tmp1->value);
	}
	else
		ft_putendl(ft_strjoin("cd: incorrect or unassigned environment path: "
			, path));
}

void			cd_env_old(t_lenv **env)
{
	t_lenv	*tmp1;
	t_lenv	*tmp2;
	char	*oldpwd;

	tmp1 = get_lenv(*env, "PWD");
	tmp2 = get_lenv(*env, "OLDPWD");
	if (tmp1 && tmp2 && access(tmp2->value, R_OK) == 0)
	{
		ft_putendl(tmp2->value);
		oldpwd = ft_strdup(tmp1->value);
		free(tmp1->value);
		tmp1->value = ft_strdup(tmp2->value);
		change_oldpwd(env);
		chdir(tmp1->value);
		free(tmp2->value);
		tmp2->value = ft_strdup(oldpwd);
		free(oldpwd);
	}
}

void			ft_cd(t_lenv **env, char **param)
{
	if (!param[1] || (param[1][0] == '~' && !param[1][1]))
		cd_home(env);
	else if (param[1][0] == '$' && param[1][1])
		cd_env(env, param[1]);
	else if (param[1][0] == '-' && !param[1][1])
		cd_env_old(env);
	else if ((param[1][0] == '/') ? check_path_spe(param[1]) :
	check_path(*env, param[1]))
	{
		if (change_oldpwd(env))
			change_pwd(env);
	}
}
