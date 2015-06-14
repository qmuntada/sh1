/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:09:05 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 16:43:06 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				check_param(char *str)
{
	if (ft_strcmp(str, "setenv") == 0)
		return (1);
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	if (ft_strcmp(str, "unsetenv") == 0)
		return (1);
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

char			*get_env(char *str, t_lenv *env)
{
	t_lenv		*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->name + 1) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

char			*check_exec(char *str, t_lenv *env)
{
	char		**tab;
	char		*path;
	int			i;

	tab = ft_strsplit(get_env("PATH", env), ':');
	if (tab == NULL)
		tab = ft_strsplit("~/", ':');
	i = -1;
	while (tab[++i])
	{
		path = ft_strjoin(tab[i], ft_strjoin("/", str));
		if (access(path, X_OK) == 0)
		{
			return (path);
		}
	}
	return (NULL);
}

char			**check_exec_param(t_lenv *env, char **param)
{
	t_lenv		*tmp;
	int			i;

	i = 0;
	while (param[i])
	{
		tmp = env;
		while (tmp)
		{
			if (ft_strcmp(param[i], tmp->name) == 0)
			{
				param[i] = ft_strdup(tmp->value);
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (param);
}
