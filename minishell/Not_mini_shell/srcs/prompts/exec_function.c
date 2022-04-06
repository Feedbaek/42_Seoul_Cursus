/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:12:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 21:46:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	execute_func(t_cmd	*head)
{
	if (!head->next && head->argv)
	{
		if (equals(head->argv[0], "echo"))
			ft_echo(head->argv, 0);
		else if (equals(head->argv[0], "cd"))
			ft_cd(head->argv, 0);
		else if (equals(head->argv[0], "pwd"))
			ft_pwd(0);
		else if (equals(head->argv[0], "export"))
			ft_export(head->argv, 0);
		else if (equals(head->argv[0], "unset"))
			ft_unset(head->argv, 0);
		else if (equals(head->argv[0], "env"))
			ft_env(0);
		else if (equals(head->argv[0], "exit"))
			ft_exit(head->argv, 0);
		else
			test_pipex(head);
	}
	else
		test_pipex(head);
	echoctl_off();
}
