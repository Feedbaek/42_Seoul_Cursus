/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:25 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/17 21:35:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_fd(int fd, t_file **file_d)
{
	t_file	*parser;
	t_file	*new_fd;

	parser = *file_d;
	if (parser)
		while (*parser)
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
	new_fd->str = (char*)malloc(1);
	new_fd->str[0] = 0;
	new_fd->next_fd = 0;
	if (parser)
		parser->next_fd = new_fd;
	*file_d = new_fd;
	return (0);
}

int		ft_split(char *a, char *b, char *str, char *n_location)
{

	if (!(a = (char*)malloc(n_location - str + 1)))
		return ;
	while (str < n_location)
		*a++ = (unsigned char)*str++;
	*a = 0;
	str++;
	if (!(b = (char*)malloc(ft_strlen(str) + 1)))
		return (0);
	while (*str)
		*b++ = (unsigned char)*str++;
	*b = 0;
	return (1);
}

int		first_process(t_file *file_d, char **str)
{
	char	*n_location;
	char	*first;
	char	*last;

	if ((n_location = ft_strchr(file_d->str, '\n')))
	{
		if (!(ft_split(first, last, file_d->str, n_location)))
			return (-1);
		free(file_d->str);
		file_d->str = last;
		*str = first;
		return (1);
	}
	*str = file_d->str;
	return (0);
}

int		second_process(int fd, t_file *file_d, char **str)
{
	int		x;
	char	*tmp;
	char	*first;
	char	*second;
	char	buf[BUFFER_SIZE + 1];

	buf[BUFFER_SIZE] = 0;
	if ((x = read(fd, buf, BUFFER_SIZE)) <= 0)
		return (x);
	if (ft_strchr(buf, '\n'))
	{
		if (!(ft_split(first, second, buf, ft_strchr(buf, '\n'))))
			return (-1);
		file_d->str = second;
		tmp = ft_strjoin(*str, first);
		free(first);
		free(*str);
		*str = tmp;
		return (0);
	}
	tmp = ft_strjoin(*str, buf);
	free(*str);
	*str = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			*str;
	char			*new;
	static t_file	*file_list;
	t_file			*file_d;
	int				x;
	int				check;

	file_d = file_list;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (check = check_fd(fd, &file_d)) == -1
		|| (x = first_process(file_d, &str)) == -1)
		return (-1);
	if (x == 1)
	{
		*line = str;
		return (1);
	}
	x = 1;
	while (x == 1)
		x = second_process(fd, file_d, &str);
	if (x == 0)
	{
		free(file_d->str);

	}
	*line = str;
	return (x);
}
