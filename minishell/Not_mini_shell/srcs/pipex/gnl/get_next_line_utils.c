/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:27 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/06 19:46:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

size_t	gnl_strlen(char *str)
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

int	gnl_strchr(char *str)
{
	int	i;

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

char	*gnl_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(gnl_strlen(s1) + 1);
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

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	if (!s1)
		return (gnl_strdup(s2));
	str = (char *)malloc(sizeof(char) * \
	(gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
	{
		free(s1);
		free(s2);
		return (0);
	}
	tmp = str;
	while (s1[i])
		*tmp++ = (unsigned char)s1[i++];
	free(s1);
	while (*s2)
		*tmp++ = (unsigned char)*s2++;
	*tmp = 0;
	return (str);
}

int	check_fd(int fd, t_file **file_list, t_file **parser)
{
	t_file	*prev;

	*parser = *file_list;
	while (*parser)
	{
		if ((*parser)->fd == fd)
			return (1);
		prev = *parser;
		*parser = (*parser)->next_fd;
	}
	*parser = (t_file *)malloc(sizeof(t_file));
	if (!parser)
		return (0);
	(*parser)->fd = fd;
	(*parser)->str = 0;
	(*parser)->next_fd = 0;
	if (!*file_list)
		*file_list = *parser;
	else
		prev->next_fd = *parser;
	return (1);
}
