/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:12:00 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 19:40:42 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <stdbool.h>
# include <termios.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include <pipex.h>
# include <get_next_line.h>

# include "../Libft/libft.h"

typedef struct s_state
{
	char	**envp;
	int		exit_status;
	int		heredoc_status;
}	t_state;

typedef struct s_parsed
{
	char	de;
	char	*token;
}	t_parsed;

extern t_state	g_state;

void	ft_echo(char **s, int flag);
void	ft_cd(char **s, int flag);
void	ft_pwd(int flag);
void	ft_export(char **s, int flag);
void	ft_unset(char **s, int flag);
void	ft_env(int flag);
void	ft_exit(char **s, int flag);

void	do_export(char *k, char *s);

void	cpy_env(char **env);
void	handle_signal(int signo);
void	handle_heredoc(int signo);

int		two_ptr_counter(char **env);
void	free_double_pointer(char ***tab);
char	*one_ret_null(char **s);
char	**d_ret_null(char ***s);
void	malloc_error(void);
int		equals(char *s1, char *s2);
char	*find_env_var(char *s);

void	echoctl_on(void);
void	echoctl_off(void);

void	print_prompt(void);
void	parser(char *s, t_cmd **head);
char	**parse_split(char const *s, char c);
void	process_env_var(char **s);
void	add_arg(t_cmd *x, char **arg);
void	process_str(char *s, char **res);
int		set_fd(int mode, char **redir, char	*filename);
void	execute_func(t_cmd	*head);
int		get_envp_idx(char **envp, char *s);

#endif
