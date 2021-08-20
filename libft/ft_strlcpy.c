/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:25:49 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 21:07:04 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(src);
	while (i < len && i + 1 < dstsize)
	{
		dest[i] = (unsigned char)src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = 0;
	return (len);
}
