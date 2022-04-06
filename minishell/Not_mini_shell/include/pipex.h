/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:09:11 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/30 17:11:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define  PIPEX_H

# include <minishell.h>

typedef struct s_cmd
{
	int				idx;
	pid_t			pid;
	int				status;
	char			*cmd;
	char			**argv;
	char			**path;
	char			**envp;
	char			*limiter;
	char			*redirect_in;
	char			*redirect_out;
	char			*redirect_out_add;
	char			*tmp;
	struct s_cmd	*next;
}				t_cmd;

int		minskim2_strncmp(const char *s1, const char *s2, size_t n);
void	run_execve(t_cmd *cmd_arg);
void	wait_pid(t_cmd *cmd_arg);
void	print_str_error(char *str);

size_t	minskim2_strlen(const char *str);
void	redirect_in(char *file, int input_fd);
void	redirect_out(char *file, int output_fd);
void	redirect_out_add(char *file, int output_fd);
int		path_finder(char **envp, t_cmd *x, char*split);
char	*minskim2_strjoin(char const *s1, char const *s2);
char	**minskim2_split(char const *s, char c);

void	here_doc(t_cmd *cmd_arg);
void	test_pipex(t_cmd *head);

#endif
