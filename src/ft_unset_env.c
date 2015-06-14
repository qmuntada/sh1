/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:45:06 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 19:01:03 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void			ft_unset_env(t_lenv **env, char **param)
{
	t_lenv		*tmp;
	int			i;

	i = 0;
	tmp = *env;
	if (!param[1])
	{
		ft_putendl("unsetenv: no argument given");
		return ;
	}
	while (param[++i])
	{
		tmp = *env;
		while (tmp)
		{
			if (ft_strcmp(tmp->name + 1, param[i]) == 0)
				*env = ft_env_relink(*env, tmp->name);
			tmp = tmp->next;
		}
	}
}
