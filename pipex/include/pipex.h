/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:26:52 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/26 16:17:00 by minskim2         ###   ########.fr       */
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
	pid_t	pid;
	int		status;
	char	*cmd;
	char	**argv;
	char	**path;
}t_cmd;

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		path_finder(char **envp, t_cmd *x, char *split);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

void	redirect_in(const char *file);
void	redirect_out(const char *file);

# define CHILD 0

#endif
