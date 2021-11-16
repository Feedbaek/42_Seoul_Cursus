/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 03:38:17 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/08 17:20:51 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "Libft/libft.h"
# include <termios.h>
# include <termcap.h>
# include <term.h>
# include <sys/ioctl.h>

# define MAXSIZE		1024

# define FALSE			0
# define TRUE			1

# define ERROR			-1
# define SUCCESS 		1

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

# define COLOR_BR_BLUE	"\033[34;1m"
# define COLOR_WHITE	"\033[37m"
# define COLOR_CYAN		"\033[36m"
# define END_COLOR		"\033[0m"

# define SYNTAX_ERROR	"Syntax error: near unexpected token!"
# define QUOTE_ERROR 	"The number of Quotes is odd!"
# define MALLOC_ERROR 	"Memory malloc fail!"
# define PIPE_ERROR 	"Pipe function is failed!"
# define FORK_ERROR 	"Fork function is failed!"

typedef struct s_redir
{
	char			*file;
	char			**inputs;
	int				index;
	bool			doub;
	struct s_redir	*next;
}				t_redir;

typedef struct s_cmd
{
	char		**cmdlines;
	char		*cmdline;
	int			flag;
	int			preflag;
	int			fds[2];
	int			redir;
	int			single_double;
	int			dup_out;
	int			dup_in;
	t_redir		*input;
	t_redir		*dinput;
	t_redir		*output;
}				t_cmd;

typedef struct s_term
{
	struct termios	term;
	struct termios	save;
	char			*cm;
	char			*ce;
}	t_term;

typedef struct s_keypos
{
	int				col;
	int				row;
}	t_keypos;

typedef struct s_save
{
	char			*input;
	int				flag;
	struct s_save	*prev;
	struct s_save	*next;
}	t_save;

typedef struct s_state
{
	t_term			t;
	t_save			*save_head;
	int				s_flag;
	char			*input;
	char			*input2;
	t_keypos		cur;
	t_keypos		max;
	t_keypos		start;
	char			**envp;
	t_list			*export;
	int				exit_status;
	int				parse_error;
	int				stop;
}	t_state;

extern t_state	g_state;

//exec
void	exec_start(t_list *cmds);

//builtins
void	ft_cd(t_cmd *cmd);
void	ft_echo(t_cmd *cmd);
void	ft_env(void);
void	ft_exit(t_cmd *cmd);
void	ft_export(t_cmd *cmd);
void	ft_pwd(void);
void	ft_unset(t_cmd *cmd);

//utils
int		ft_isnumeric(char *str);
void	set_env_export(char **envs);
char	*find_value(char *key);
void	set_export(t_list *target, char **content);
int		ft_change_env(char *key, char *str);
void	free_dp(char **str);
void	free_list(t_list *cmds);
void	close_fd(t_cmd *cmd);

//error
void	print_exec_error_1(char *str1);
void	print_exec_error_2(char *str1, char *str2);
void	print_exec_error_3(char *str1, char *str2, char *str3);
void	print_malloc_error(void);

//parse
char	**parse_split(char const *s, char c);
int		parse_pipe(char *line, t_list *cmds);
int		parse_cmd(t_cmd *cmd);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2);

//redirect
void	exec_redir(t_cmd *cmd);
t_redir	*make_redir(t_redir **list);
void	make_redir2(t_cmd *cmd);
int		find_var(char *str, char **result);
int		check_redir(t_cmd *cmd);
void	put_inputs(t_redir *new);
void	clear_temp(void);
int		check_quote(char *str);
char	*make_str(char *str);
int		use_temp(t_cmd *cmd, int fd, int i);

/*
**	prompt
*/
void	prompt2(t_state *state);
void	prompt3(t_state *state);
int		is_backslash(t_state *s);
void	handle_eof(t_state *s, char *input);

//add
int		get_command_line(char **input);
int		get_input(char **line);

/*
**	term
*/
void	init_term(t_state *s);
void	handle_keycode(t_state *s, int keycode);
int		term_loop(t_state *s);
void	put_backspace(t_state *s);

/*
**	history
*/
void	save_history(t_state *s);
t_save	*push_front_save(char *input, t_save *old_head, int flag);
void	reset_save(t_state *s);
void	press_up(t_state *s);
void	press_down(t_state *s);

/*
**	string_util
*/
int		ft_putchar(int c);
char	*ft_strcjoin(char *str, char c);
void	print_save_char(t_state *s, char c);
char	*delete_last_char(char *str);
void	print_mini(void);

/*
**	signal
*/
void	handle_signal(int signo);

/*
**	cursor
*/
int		get_nbr_len(int n);
void	set_cursor(int *col, int *row);
void	set_cursor_win(t_state *s);
void	prepare_token_and_cmd(t_state *state);

#endif
