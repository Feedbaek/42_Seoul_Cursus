/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:22 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/06 19:49:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_file
{
	int				fd;
	char			*str;
	struct s_file	*next_fd;
}				t_file;

size_t	gnl_strlen(char *str);
int		gnl_strchr(char *str);
char	*gnl_strdup(char *s1);
char	*gnl_strjoin(char *s1, char *s2);
int		ret_free(char *buf, int ret);
int		gnl_split(char **hi, int n_idx, char **line);
int		wtf_output(t_file *file_d, char **line,
			int read_size, char *buf);
int		check_fd(int fd, t_file **file_list, t_file **parser);

char	*valid_set(int fd, char **line, t_file **file_list, t_file **file_d);
int		gnl_while(char *buf, int *n_idx, char **line, t_file *file_d);

int		get_next_line(int fd, char **line);

#endif
