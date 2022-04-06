/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:13:47 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/13 18:19:54 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			idx;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	idx = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (idx < n)
	{	
		dst_temp[idx] = src_temp[idx];
		if (src_temp[idx] == (unsigned char)c)
			break ;
		idx++;
	}
	if (idx != n)
		return (dst_temp + idx + 1);
	return (NULL);
}
