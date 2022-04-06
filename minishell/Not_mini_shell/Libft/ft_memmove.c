/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:02:39 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/17 11:26:26 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	idx = -1;
	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	if (dst > src)
		while (++idx < len)
			dst_temp[len - idx - 1] = src_temp[len - idx - 1];
	else
		while (++idx < len)
			dst_temp[idx] = src_temp[idx];
	return (dst);
}
