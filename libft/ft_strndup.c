/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:20:47 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/12 14:37:29 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *str, int n)
{
	char *dst;

	dst = (char *)malloc(sizeof(char) * n + 1);
	dst = ft_strncpy(dst, str, n);
	dst[n] = '\0';
	return (dst);
}
