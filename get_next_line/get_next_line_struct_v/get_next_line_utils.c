/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:27 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/23 22:03:49 by minskim2         ###   ########.fr       */
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

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == 0)
		return ((char*)str);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*tmp;

	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	tmp = str;
	if (s1)
		while (*s1)
			*str++ = (unsigned char)*s1++;
	if (s2)
		while (*s2)
			*str++ = (unsigned char)*s2++;
	*str = 0;
	return (tmp);
}

int		check_fd(int fd, t_file **file_d)
{
	t_file	*parser;
	t_file	*new_fd;

	parser = *file_d;
	if (parser)
		while (parser)
		{
			if (parser->fd == fd)
			{
				*file_d = parser;
				return (1);
			}
			if (!(parser->next_fd))
				break ;
			parser = parser->next_fd;
		}
	if (!(new_fd = (t_file*)malloc(sizeof(t_file))))
		return (-1);
	new_fd->fd = fd;
	new_fd->str = 0;
	new_fd->next_fd = 0;
	if (parser)
		parser->next_fd = new_fd;
	*file_d = new_fd;
	return (0);
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
