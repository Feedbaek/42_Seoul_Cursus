/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:47:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 19:44:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	minskim2_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (i == n)
		i--;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	run_execve(t_cmd *cmd_arg)
{
	if (equals(cmd_arg->argv[0], "echo"))
		ft_echo(cmd_arg->argv, 1);
	else if (equals(cmd_arg->argv[0], "cd"))
		ft_cd(cmd_arg->argv, 1);
	else if (equals(cmd_arg->argv[0], "pwd"))
		ft_pwd(1);
	else if (equals(cmd_arg->argv[0], "export"))
		ft_export(cmd_arg->argv, 1);
	else if (equals(cmd_arg->argv[0], "unset"))
		ft_unset(cmd_arg->argv, 1);
	else if (equals(cmd_arg->argv[0], "env"))
		ft_env(1);
	else if (equals(cmd_arg->argv[0], "exit"))
		ft_exit(cmd_arg->argv, 1);
	else
	{
		echoctl_on();
		if (execve(cmd_arg->cmd, cmd_arg->argv, g_state.envp) == -1)
		{
			printf("bash: %s: %s\n", cmd_arg->cmd, "command not found");
			exit(127);
		}
	}
}

void	wait_pid(t_cmd *cmd_arg)
{
	t_cmd	*parser;

	parser = cmd_arg;
	while (parser)
	{
		waitpid(parser->pid, &(parser->status), 0);
		g_state.exit_status = parser->status % 255;
		if (parser->status == SIGQUIT)
		{
			ft_putendl_fd("Quit: 3", 2);
			g_state.exit_status = 131;
		}
		parser = parser->next;
	}
	parser = cmd_arg;
	while (parser)
	{
		if (parser->limiter)
		{
			unlink(parser->tmp);
			free(parser->tmp);
		}
		parser = parser->next;
	}
}

void	print_str_error(char *str)
{
	printf("bash: %s: %s\n", str, strerror(errno));
	exit(1);
}
