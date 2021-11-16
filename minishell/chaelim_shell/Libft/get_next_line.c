/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:25:53 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 20:39:29 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_newline(char *backup)
{
	int			i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	check_newline(char **backup, char **line, int i)
{
	char		*temp;

	(*backup)[i] = '\0';
	*line = ft_strdup(*backup);
	temp = ft_strdup(*backup + i + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

static int	not_check_newline(char **backup, char **line)
{
	*line = ft_strdup(*backup);
	free(*backup);
	*backup = 0;
	return (0);
}

static int	finally(char **backup, char **line, int i, int fd)
{
	if (i >= 0)
		return (check_newline(&backup[fd], line, i));
	return (not_check_newline(&backup[fd], line));
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			read_buf;
	int			line_buf;

	if (fd < 0 || BUFFER_SIZE < 1 || line == 0)
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	read_buf = read(fd, buf, BUFFER_SIZE);
	while (read_buf > 0)
	{
		buf[read_buf] = '\0';
		temp = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = temp;
		line_buf = read_newline(backup[fd]);
		if (line_buf >= 0)
			return (check_newline(&backup[fd], line, line_buf));
	}
	if (read_buf == -1)
		return (-1);
	line_buf = read_newline(backup[fd]);
	return (finally(&backup[fd], line, line_buf, fd));
}
