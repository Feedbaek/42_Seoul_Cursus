/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:15:02 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 00:42:19 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_exit(int code, int flag, int cmdflag)
{
	if (flag == 0)
		ft_putstr_fd("exit\n", STDOUT);
	if (cmdflag == 1)
		exit(0);
	exit(code);
}

void	exit_errcode_1(char *str, int preflag, int flag)
{
	if (!(preflag || flag))
		ft_putstr_fd("exit\n", STDERR);
	print_exec_error_3("exit", str, "numeric argument required");
	if (flag == 1)
		exit(0);
	exit(255);
}

void	exit_errcode_2(int preflag, int flag)
{
	if (!(preflag || flag))
		ft_putstr_fd("exit\n", STDERR);
	print_exec_error_2("exit", "too many arguments");
	if (flag == 1)
		exit(0);
	else if (preflag == 1)
		exit(1);
	else
		g_state.exit_status = 1;
}

void	ft_exit(t_cmd *cmd)
{
	int		i;
	char	**cmds;
	int		flag;

	i = 0;
	flag = cmd->flag || cmd->preflag;
	cmds = cmd->cmdlines;
	while (cmds[i])
		i++;
	if (i == 1)
		print_exit(0, flag, cmd->flag);
	if (i > 2)
		exit_errcode_2(cmd->preflag, cmd->flag);
	else
	{
		g_state.exit_status = ft_isnumeric(cmds[1]);
		if (g_state.exit_status == -1)
			exit_errcode_1(cmds[1], cmd->preflag, cmd->flag);
		print_exit(g_state.exit_status, flag, cmd->flag);
	}
}
