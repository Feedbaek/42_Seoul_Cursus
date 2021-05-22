/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:22 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/17 15:11:34 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_gnlcat(char *dest, char *src, size_t size);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);

typedef struct	s_file
{
	int				fd;
	char			*buf;
	struct	s_file	*next_fd;
}				t_file;

#endif
