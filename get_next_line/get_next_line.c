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

int		get_next_line(int fd, char **line)
{
	char		*str;
	char		*check;
	char		*tmp;
	static char	*buf[OPEN_MAX + 1];
	int			x;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!buf[fd])//  문제있음
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
	return (1);
}
