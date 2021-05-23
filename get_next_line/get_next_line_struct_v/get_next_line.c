/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:25 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/23 22:00:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_split(char **a, char **b, char *str, char *n_location)
{
	int		len;
	char	*first;
	char	*last;

	len = ft_strlen(str);
	if (!(first = (char*)malloc(ft_strlen(str) - ft_strlen(n_location) + 1)))
		return (0);
	while (str < n_location)
		*first++ = (unsigned char)*str++;
	*first = 0;
	str++;
	if (!(last = (char*)malloc(len - ft_strlen(first))))
		return (0);
	while (*str)
		*last++ = (unsigned char)*str++;
	*last = 0;
	*a = first;
	*b = last;
	return (1);
}

int		first_process(t_file *file_d, char **str)
{
	char	*n_location;
	char	*first;
	char	*last;

	if ((n_location = ft_strchr(file_d->str, '\n')))
	{
		if (!(ft_split(&first, &last, file_d->str, n_location)))
			return (-1);
		//free(file_d->str);
		file_d->str = last;
		*str = first;
		return (1);
	}
	*str = ft_strdup(file_d->str);
	//free(file_d->str);
	return (0);
}

int		second_process(int fd, t_file *file_d, char **str)
{
	int		x;
	char	*tmp;
	char	*first;
	char	*second;
	char	*buf;

	if (!(buf = (char*)malloc(BUFFER_SIZE + 1)))
		return (0);
	if ((x = read(fd, buf, BUFFER_SIZE)) <= 0)
	{
		//free(buf);
		return (x);
	}
	buf[x] = 0;
	if (ft_strchr(buf, '\n'))
	{
		if (!(ft_split(&first, &second, buf, ft_strchr(buf, '\n'))))
			return (-1);
		file_d->str = second;
		tmp = ft_strjoin(*str, first);
		//free(first);
		//free(*str);
		//free(buf);
		*str = tmp;
		return (0);
	}
	tmp = ft_strjoin(*str, buf);
	//free(*str);
	//free(buf);
	*str = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			*str;
	static t_file	*file_list;
	t_file			*file_d;
	int				x;
	int				check;

	if (!file_list)
		check_fd(fd, &file_list);
	file_d = file_list;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((check = check_fd(fd, &file_d)) == -1
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
	*line = str;
	return (x);
}
