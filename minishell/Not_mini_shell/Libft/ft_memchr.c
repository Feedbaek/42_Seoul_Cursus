/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:18:56 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/13 18:20:11 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*temp;

	idx = 0;
	temp = (unsigned char *)s;
	while (idx < n)
	{
		if (temp[idx] == (unsigned char)c)
			break ;
		idx++;
	}
	if (idx == n)
		return (NULL);
	return (temp + idx);
}
