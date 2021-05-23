/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:19:35 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/23 23:01:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split(char **hi, int n_idx)
{
	int		i;
	char	*str;
	char	*new_str;
	char	*new_hi;

	str = *hi;
	i = 0;
	if (!(new_str = (char*)malloc(n_idx + 1)))
		return (0);
	while (i < n_idx)
		new_str[i++] = (unsigned char)*str++;
	new_str[i] = 0;
	str++;
	if (!(new_hi = (char*)malloc(ft_strlen(*hi) - n_idx + 1)))
		return (0);
	i = 0;
	while (*str)
		new_hi[i++] = (unsigned char)*str++;
	new_hi[i] = 0;
	free(*hi);
	*hi = new_hi;
	return (new_str);
}

int		WTF_output(char **hi, char **line, int read_size)
{
	int		n_idx;

	if (read_size < 0)
		return (-1);
	if ((n_idx = ft_strchr(*hi)) >= 0)
	{
		*line = ft_split(hi, n_idx);
		return (1);
	}
	if (*hi)
	{
		*line = *hi;
		*hi = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*hi[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			n_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		hi[fd] = ft_strjoin(hi[fd], buf);
		if ((n_idx = ft_strchr(hi[fd])) >= 0)
		{
			*line = ft_split(&hi[fd], n_idx);
			return (1);
		}
	}
	return (WTF_output(&hi[fd], line, read_size));
}