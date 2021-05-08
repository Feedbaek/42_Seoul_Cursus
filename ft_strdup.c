/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:55:54 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	p = (char*)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (p);
	len = ft_strlen(s1);
	ft_memcpy(p, s1, len);
	p[len] = 0;
	return (p);
}
