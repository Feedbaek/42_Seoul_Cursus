/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:39:09 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 18:00:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*exit_so_long(void)
{
	perror("Error\n");
	exit(0);
}

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
