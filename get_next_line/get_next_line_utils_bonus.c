/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:27 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/24 11:18:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int		ft_strchr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char*)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (p);
	while (s1[i])
	{
		p[i] = (unsigned char)s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	tmp = str;
	while (s1[i])
		*tmp++ = (unsigned char)s1[i++];
	free(s1);
	while (*s2)
		*tmp++ = (unsigned char)*s2++;
	*tmp = 0;
	return (str);
}
