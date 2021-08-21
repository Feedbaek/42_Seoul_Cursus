/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:47:25 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/21 16:06:59 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*valid_set(int fd, char **line, t_file **file_list, t_file **file_d)
{
	char	*buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0
		|| !(check_fd(fd, file_list, file_d)))
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	return (buf);
}

int	gnl_while(char *buf, int *n_idx, char **line, t_file *file_d)
{
	file_d->str = ft_strjoin(file_d->str, buf);
	if (!file_d->str)
		return (ret_free(buf, -1));
	*n_idx = ft_strchr(file_d->str);
	if (*n_idx >= 0)
	{
		if (!(ft_split(&(file_d->str), *n_idx, line)))
			return (ret_free(buf, -1));
		return (ret_free(buf, 1));
	}
	return (0);
}
