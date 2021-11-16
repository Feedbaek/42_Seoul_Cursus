/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:06:57 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 20:06:58 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*p1;
	char	*p2;
	size_t	i;
	size_t	j;

	if (dest == 0 && src == 0)
		return (NULL);
	p1 = (char *)dest;
	p2 = (char *)src;
	i = 1;
	j = -1;
	if (p1 > p2)
	{
		while (i <= len)
		{
			p1[len - i] = p2[len - i];
			i++;
		}
	}
	else
	{
		while (++j < len)
			p1[j] = p2[j];
	}
	return (dest);
}
