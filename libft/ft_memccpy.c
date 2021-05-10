/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:20:12 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*tmp;
	size_t				i;
	const unsigned char	*s = src;

	tmp = (char *)dest;
	i = 0;
	if (!n && !dest)
		return ((void *)0);
	while (i < n)
	{
		tmp[i] = s[i];
		if ((unsigned char)c == s[i])
			break ;
		i++;
	}
	if (n == i)
		return ((void*)0);
	return (dest + i + 1);
}
