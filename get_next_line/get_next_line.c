/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:19:35 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/08 15:34:47 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		link_free(t_file **file_list, int ret, t_file *file_d)
{
	t_file *prev;
	t_file *parser;

	if (ret > 0)
		return (ret);
	parser = *file_list;
	if (*file_list == file_d)
		*file_list = file_d->next_fd;
	else
	{
		while (parser)
		{
			if (parser->fd == file_d->fd)
				break ;
			prev = parser;
			parser = parser->next_fd;
		}
		prev->next_fd = file_d->next_fd;
	}
	if (ret < 0 && file_d->str)
		free(file_d->str);
	free(file_d);
	return (ret);
}

int		ret_free(char *buf, int ret)
{
	free(buf);
	return (ret);
}

int		ft_split(char **hi, int n_idx, char **line)
{
	int		i;
	char	*str;
	char	*new_str;
	char	*new_hi;

	str = *hi;
	i = 0;
	if (!(new_str = (char*)malloc(sizeof(char) * (n_idx + 1))))
		return (ret_free(*hi, 0));
	while (i < n_idx)
		new_str[i++] = (unsigned char)*str++;
	new_str[i] = 0;
	str++;
	if (!(new_hi = ft_strdup(str)))
	{
		free(new_str);
		return (ret_free(*hi, 0));
	}
	free(*hi);
	*hi = new_hi;
	*line = new_str;
	return (1);
}

int		wtf_output(t_file *file_d, char **line, int read_size, char *buf)
{
	int		n_idx;

	if (read_size < 0)
		return (ret_free(buf, -1));
	if ((n_idx = ft_strchr(file_d->str)) >= 0)
	{
		if (!(ft_split(&(file_d->str), n_idx, line)))
			return (ret_free(buf, -1));
		return (ret_free(buf, 1));
	}
	if (file_d->str)
	{
		*line = file_d->str;
		file_d->str = 0;
		return (ret_free(buf, 0));
	}
	if (!(*line = ft_strdup("")))
		return (ret_free(buf, -1));
	return (ret_free(buf, 0));
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	int				read_size;
	int				n_idx;
	static t_file	*file_list;
	t_file			*file_d;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
	!(file_d = check_fd(fd, &file_list)))
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		if (!(file_d->str = ft_strjoin(file_d->str, buf)))
			return (ret_free(buf, -1));
		if ((n_idx = ft_strchr(file_d->str)) >= 0)
		{
			if (!(ft_split(&(file_d->str), n_idx, line)))
				return (ret_free(buf, -1));
			return (ret_free(buf, 1));
		}
	}
	n_idx = wtf_output(file_d, line, read_size, buf);
	return (link_free(&file_list, n_idx, file_d));
}
