/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <qmuntada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:24:30 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/10 10:00:17 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_lenv			*ft_parse(t_lenv *env, char **param)
{
	if (ft_strcmp(param[0], "cd") == 0)
		ft_cd(&env, param);
	else if (ft_strcmp(param[0], "setenv") == 0)
		ft_setenv(&env, param);
	else if (ft_strcmp(param[0], "unsetenv") == 0)
		ft_unset_env(&env, param);
	else if (ft_strcmp(param[0], "exit") == 0)
		ft_exit(param);
	return (env);
}
