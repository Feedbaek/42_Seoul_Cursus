/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:45:45 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/28 18:34:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	minskim2_strlen(const char *str)
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

static	size_t	minskim2_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = minskim2_strlen(src);
	while (i < len && i + 1 < dstsize)
	{
		dest[i] = (unsigned char)src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = 0;
	return (len);
}

static	size_t	minskim2_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

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

char	*minskim2_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = malloc((minskim2_strlen(s1) + minskim2_strlen(s2) + 1));
	if (!str)
		return (0);
	(void)minskim2_strlcpy(str, s1, minskim2_strlen(s1) + 1);
	(void)minskim2_strlcat(str, s2, minskim2_strlen(s1) \
		+ minskim2_strlen(s2) + 1);
	return (str);
}
