/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:46:31 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 19:03:06 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_lenv			*get_lenv(t_lenv *env, char *str)
{
	t_lenv		*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->name + 1) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				check_setenv(t_lenv **env, char *param)
{
	char	**new_env;
	char	*value;
	t_lenv	*tmp;

	new_env = ft_strsplit(param, '=');
	if (!new_env[0] || !new_env[1] || !new_env[0][0] || !new_env[1][0]
		|| new_env[2])
		return (0);
	value = ft_strdup(new_env[1]);
	if (value[0] == '$' && value[1])
	{
		tmp = get_lenv(*env, value + 1);
		if (!tmp)
			return (0);
		value = tmp->value;
	}
	tmp = get_lenv(*env, new_env[0]);
	if (tmp)
		tmp->value = ft_strdup(value);
	else
		env_push_back(env, new_env[0], value);
	return (1);
}

void			ft_setenv(t_lenv **env, char **param)
{
	int			i;

	i = 0;
	if (!param[1])
	{
		ft_putendl("setenv: no argument given");
		return ;
	}
	while (param[++i])
	{
		if (!param[i][0] || !check_setenv(env, param[i]))
		{
			ft_putendl(ft_strjoin("sh1: ", ft_strjoin(param[i],
				": bad assignment")));
			return ;
		}
	}
}
