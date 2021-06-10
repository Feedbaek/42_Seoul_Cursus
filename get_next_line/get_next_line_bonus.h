/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:22 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/08 15:36:00 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_file
{
	int				fd;
	char			*str;
	struct s_file	*next_fd;
}				t_file;

size_t			ft_strlen(char *str);
int				ft_strchr(char *str);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);
int				link_free(t_file **file_list, int ret, t_file *file_d);
int				ret_free(char *buf, int ret);
int				ft_split(char **hi, int n_idx, char **line);
int				wtf_output(t_file *file_d, char **line,
				int read_size, char *buf);
t_file			*check_fd(int fd, t_file **file_list);

int				get_next_line(int fd, char **line);

#endif
