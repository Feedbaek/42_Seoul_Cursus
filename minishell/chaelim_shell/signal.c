/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:52:13 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/08 21:53:35 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			write(1, "\nbash> ", 7);
			if (g_state.input)
				free(g_state.input);
			g_state.input = 0;
			g_state.exit_status = 130;
		}
		else
		{
			write(1, "\n", 1);
		}
	}
	if (signo == SIGQUIT)
	{
		if (pid != -1)
		{
			write(1, "Quit: 3\n", 8);
			g_state.exit_status = 131;
		}
	}
}
