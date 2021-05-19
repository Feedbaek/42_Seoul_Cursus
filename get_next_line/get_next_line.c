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

int		check_fd(int fd, t_file *file_d)
{
	t_file	*parser;
	t_file	*new_fd;

	parser = file_d;
	if (parser)
		while (*parser)
		{
			if (parser->fd == fd)
			{
				file_d = parser;
				return (1);
			}
			if (!(parser->next_fd))
				break ;
			parser = parser->next_fd;
		}
	if (!(new_fd = (t_file*)malloc(sizeof(t_file))))
		return (-1);
	new_fd->fd = fd;
	new_fd->buf[BUFFER_SIZE] = 0;
	new_fd->next_fd = 0;
	if (parser)
		parser->next_fd = new_fd;
	file_d = new_fd;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*str;
	int				num;
	static t_file	*file_d;
	int				x;
	int				check;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (check = check_fd(fd, file_d)) == -1)
		return (-1);
	if (check == 1)
	{
		if (!(str = (char*)malloc(ft_strlen(file_d->buf) + BUFFER_SIZE + 1)))
			return (-1);
		num = ft_gnlcat(str, file_d->buf, ft_strlen(file_d->buf) + BUFFER_SIZE + 1);
		if ()
	}
	x = read(fd, file_d->buf, BUFFER_SIZE);
	if (x == -1)
		return (-1);
	if (!(str = (char*)malloc(x + 1)))
		return (-1);
	file_d->buf[x] = 0;

/*
	if (!buf[fd])
		if (!(buf[fd] = (char*)malloc(BUFFER_SIZE + 1)))
			return (-1);
	if (!(str = (char*)malloc(ft_strlen(buf[fd]) + 1))
		|| (x = read(fd, buf[fd], BUFFER_SIZE)) == -1)
		return (-1);
	buf[fd][BUFFER_SIZE] = 0;
	ft_memmove(str, buf, BUFFER_SIZE + 1);
	while ((x = read(fd, buf[fd], BUFFER_SIZE)) == 1)
	{
		if (!(tmp = ft_strdup(str)))
			return (-1);
		free(str);
		if (!(str = (char*)malloc(ft_strlen(tmp) + x + 1)))
			return (-1);
		ft_memmove(str, tmp, ft_strlen(tmp) + 1);
		free(tmp);
		check = ft_gnlcat(str, buf, ft_strlen(str) + BUFFER_SIZE + 1);
		if (*check == '\n')
		{
			check++;
			break ;
		}
	}
	ft_memmove(buf, check, ft_strlen(check));
	*line = str;
	if (x == 0 || x == -1)
		return (x);
*/
	return (1);
}
