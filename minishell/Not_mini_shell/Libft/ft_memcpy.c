/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:20:42 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/17 11:26:21 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	idx = 0;
	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	while (idx < n)
	{
		dst_temp[idx] = src_temp[idx];
		idx++;
	}
	return (dst);
}
