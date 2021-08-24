/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:30:02 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 00:06:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	s = (unsigned char *)src;
	tmp = (unsigned char *)dest;
	while (n--)
		*tmp++ = *s++;
	return (dest);
}

void	error_push_swap(char *error)
{
	ft_putstr(error);
	exit(0);
}
