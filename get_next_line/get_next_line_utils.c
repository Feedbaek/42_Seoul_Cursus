/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:27 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/23 22:43:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int		ft_strchr(char *str, int c)
{
	int		i;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if ((unsigned char)c == 0)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	str = 0;
	i = 0;
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	if (s1)
		while (*s1)
			*str++ = (unsigned char)*s1++;
	free(s1)
	if (s2)
		while (*s2)
			*str++ = (unsigned char)*s2++;
	*str = 0;
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*p;

	p = (char*)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (p);
	if (s1)
		while (*s1)
			*p++ = (unsigned char)*s1++;
	*p = 0;
	return (p);
}
