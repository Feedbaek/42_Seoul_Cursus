/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:44:52 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:52 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	char_dst = dst;
	char_src = (unsigned char *)src;
	while (i < len)
	{
		char_dst[i] = char_src[i];
		i++;
	}
	return (dst);
}
