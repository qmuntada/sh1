/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:45:16 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 16:50:41 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_exit(char **param)
{
	if (param[1])
	{
		if (param[2])
			ft_putendl("exit: too many arguments");
		else
			exit(ft_atoi(param[1]));
	}
	else
		exit(0);
}
