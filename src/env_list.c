/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:10:06 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/14 18:56:58 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static t_lenv		*env_new(char *name, char *value)
{
	t_lenv			*new;

	new = (t_lenv*)malloc(sizeof(t_lenv));
	new->value = ft_strdup(value);
	new->name = ft_strjoin("$", name);
	new->next = NULL;
	return (new);
}

void				env_push_back(t_lenv **list, char *name, char *value)
{
	t_lenv			*new;

	new = *list;
	if (new)
	{
		while (new->next)
			new = new->next;
		new->next = env_new(name, value);
	}
	else
	{
		*list = env_new(name, value);
	}
}

t_lenv				*create_list(char **tab)
{
	t_lenv			*begin;
	int				i;
	int				b;

	begin = NULL;
	i = -1;
	while (tab[++i])
	{
		b = -1;
		while (tab[i][++b])
			if (tab[i][b] == '=')
				env_push_back(&begin, ft_strndup(tab[i], b), tab[i] + b + 1);
	}
	return (begin);
}

char				**list_to_char(t_lenv *list)
{
	t_lenv			*tmp;
	char			**dst;
	int				i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	dst = (char **)malloc(sizeof(char *) * i + 1);
	i = -1;
	while (list)
	{
		dst[++i] = ft_strjoin(list->name + 1, ft_strjoin("=", list->value));
		list = list->next;
	}
	dst[i + 1] = NULL;
	return (dst);
}

t_lenv				*ft_env_relink(t_lenv *cur, char *name)
{
	t_lenv		*tmp;

	if (!cur)
		return (NULL);
	if (ft_strcmp(cur->name, name) == 0)
	{
		tmp = cur->next;
		free(cur);
		cur = NULL;
		return (tmp);
	}
	cur->next = ft_env_relink(cur->next, name);
	return (cur);
}
