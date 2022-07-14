/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:44:33 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:47 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	i = 0;
	char_dst = dst;
	char_src = (unsigned char *)src;
	while (i < len)
	{
		char_dst[i] = char_src[i];
		if (char_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
