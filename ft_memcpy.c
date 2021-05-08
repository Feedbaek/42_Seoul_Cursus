/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:14:28 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	s = (unsigned char*)src;
	tmp = (unsigned char*)dest;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*tmp++ = *s++;
	return (dest);
}
