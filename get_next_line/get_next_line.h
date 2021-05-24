/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:22 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/24 11:37:14 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX 256

size_t	ft_strlen(char *str);
int		ft_strchr(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_split(char **hi, int n_idx);
int		WTF_output(char **hi, char **line, int read_size);
int		get_next_line(int fd, char **line);

int		get_next_line(int fd, char **line);

#endif
