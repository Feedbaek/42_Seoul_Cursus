/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:27 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/16 19:56:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest == 0 && src == 0)
		return (0);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

char	*ft_gnlcat(char *dest, char *src, size_t size)
{
	size_t i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	while (i + 1 < size && *src && *src != '\n')
	{
		((unsigned char*)dest)[i] = (unsigned char)*src;
		src++;
		i++;
	}
	if (i < size)
		dest[i] = 0;
	if (*src == '\n')
		return (src);
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	if (!s1)
	{
		p = (char*)malloc(1);
		p[0] = 0;
		return (p);
	}
	p = (char*)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (p);
	len = ft_strlen(s1);
	ft_memmove(p, s1, len);
	p[len] = 0;
	return (p);
}
