/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:44:56 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:53 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*char_dst;
	unsigned char	*char_src;

	if (!dst && !src)
		return (NULL);
	char_dst = dst;
	char_src = (unsigned char *)src;
	if (char_dst < char_src)
	{
		while (len--)
			*char_dst++ = *char_src++;
	}
	else
	{
		char_dst = &char_dst[len - 1];
		char_src = &char_src[len - 1];
		while (len--)
			*char_dst-- = *char_src--;
	}
	return (dst);
}
