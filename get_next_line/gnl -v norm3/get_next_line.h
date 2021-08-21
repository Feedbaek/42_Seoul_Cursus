/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:19:22 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/21 16:08:33 by minskim2         ###   ########.fr       */
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

size_t	ft_strlen(char *str);
int		ft_strchr(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		link_free(t_file **file_list, int ret, t_file *file_d);
int		ret_free(char *buf, int ret);
int		ft_split(char **hi, int n_idx, char **line);
int		wtf_output(t_file *file_d, char **line,
			int read_size, char *buf);
int		check_fd(int fd, t_file **file_list, t_file **parser);

char	*valid_set(int fd, char **line, t_file **file_list, t_file **file_d);
int		gnl_while(char *buf, int *n_idx, char **line, t_file *file_d);

int		get_next_line(int fd, char **line);

#endif
