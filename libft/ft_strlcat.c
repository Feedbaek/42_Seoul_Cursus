/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:39:46 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (*dest && i < size)
	{
		dest++;
		i++;
	}
	while (i + 1 < size && *src)
	{
		*dest = (unsigned char)*src;
		dest++;
		src++;
		i++;
	}
	if (i < size)
		*dest = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}
