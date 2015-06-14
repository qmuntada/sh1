/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 13:43:19 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 18:58:35 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void		print_prompt(void)
{
	ft_putstr("$>>");
}

void		handler(void)
{
	if (g_bool == 0)
	{
		g_bool = 2;
		ft_putchar('\n');
		print_prompt();
	}
	else
	{
		ft_putchar('\n');
		if (g_bool != 1)
			print_prompt();
	}
}

int			main(int ac, char **av, char **env)
{
	t_lenv		*env_cpy;
	char		*line;

	(void)ac;
	(void)av;
	env_cpy = create_list(env);
	print_prompt();
	signal(SIGINT, (void(*)())handler);
	while (get_next_line(0, &line))
		env_cpy = core(env_cpy, line);
	return (0);
}
