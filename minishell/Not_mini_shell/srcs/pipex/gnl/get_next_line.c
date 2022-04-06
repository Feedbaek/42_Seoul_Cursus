/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:19:35 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/06 19:50:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static int	link_free(t_file **file_list, int ret, t_file *file_d)
{
	t_file	*prev;
	t_file	*parser;

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

int	ret_free(char *buf, int ret)
{
	free(buf);
	return (ret);
}

int	gnl_split(char **hi, int n_idx, char **line)
{
	int		i;
	char	*str;
	char	*new_str;
	char	*new_hi;

	str = *hi;
	i = 0;
	new_str = (char *)malloc(sizeof(char) * (n_idx + 1));
	if (!new_str)
		return (ret_free(*hi, 0));
	while (i < n_idx)
		new_str[i++] = (unsigned char)*str++;
	new_str[i] = 0;
	str++;
	new_hi = gnl_strdup(str);
	if (!new_hi)
	{
		free(new_str);
		return (ret_free(*hi, 0));
	}
	free(*hi);
	*hi = new_hi;
	*line = new_str;
	return (1);
}

int	wtf_output(t_file *file_d, char **line, int read_size, char *buf)
{
	int	n_idx;

	if (read_size < 0)
		return (ret_free(buf, -1));
	n_idx = gnl_strchr(file_d->str);
	if (n_idx >= 0)
	{
		if (!(gnl_split(&(file_d->str), n_idx, line)))
			return (ret_free(buf, -1));
		return (ret_free(buf, 1));
	}
	if (file_d->str)
	{
		*line = file_d->str;
		file_d->str = 0;
		return (ret_free(buf, 0));
	}
	*line = gnl_strdup("");
	if (!*line)
		return (ret_free(buf, -1));
	return (ret_free(buf, 0));
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				read_size;
	int				n_idx;
	static t_file	*file_list;
	t_file			*file_d;

	buf = valid_set(fd, line, &file_list, &file_d);
	if (!buf)
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = 0;
		read_size = gnl_while(buf, &n_idx, line, file_d);
		if (read_size != 0)
			return (read_size);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	n_idx = wtf_output(file_d, line, read_size, buf);
	return (link_free(&file_list, n_idx, file_d));
}
