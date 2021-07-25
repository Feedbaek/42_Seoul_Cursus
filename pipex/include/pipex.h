/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:26:52 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/25 17:21:56 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_cmd
{
	int		pipe[2];
	char	*cmd;
	char	**argv;
	char	**path;
}t_cmd;

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		path_finder(char **envp, t_cmd *x, char *split);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

int		redirect_in(const char *file);
int		redirect_out(const char *file);

# define CHILD 0

# define IN_FILE argv[1]
# define OUT_FILE argv[4]
# define CMD_1 argv[2]
# define CMD_2 argv[3]

#endif
