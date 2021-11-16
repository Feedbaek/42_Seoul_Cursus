/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:57:50 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 21:16:13 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_inputs(t_redir *new)
{
	char	**new_inputs;
	int		i;

	i = -1;
	new_inputs = (char **)malloc(sizeof(char *) * (new->index + 1));
	while (new->inputs[++i])
		new_inputs[i] = new->inputs[i];
	new_inputs[i] = new->file;
	new->file = 0;
	new_inputs[i + 1] = 0;
	free(new->inputs);
	new->inputs = new_inputs;
}

void	make_redir2(t_cmd *cmd)
{
	t_redir	*new;

	new = (t_redir *)malloc(sizeof(t_redir));
	cmd->dinput = new;
	if (!new)
		print_malloc_error();
	new->doub = false;
	new->next = 0;
	new->file = 0;
	new->index = 0;
	new->inputs = (char **)malloc(sizeof(char *));
	(new->inputs)[new->index] = 0;
}

t_redir	*make_redir(t_redir **list)
{
	t_redir	*new;
	t_redir	*cur;

	new = (t_redir *)malloc(sizeof(t_redir));
	if (!new)
		print_malloc_error();
	new->doub = false;
	new->next = 0;
	new->file = 0;
	new->inputs = 0;
	new->index = 0;
	cur = *list;
	if (!cur)
		*list = new;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	return (new);
}

void	clear_temp(void)
{
	char	*argv[3];
	int		pid;
	int		st;

	st = 0;
	argv[0] = "-f";
	argv[1] = "./.temp";
	argv[2] = NULL;
	pid = fork();
	if (pid == 0)
		exit(execve("/bin/rm", (char **)argv, NULL));
	waitpid(pid, &st, 0);
}

int	check_quote(char *str)
{
	int	len;

	len = 0;
	while ((str[len] != 0) && (str[len] != '>') \
	&& (str[len] != '<'))
	{
		if (str[len] == '\'')
		{
			while (str[len + 1] != '\'')
				len++;
			len++;
		}
		if (str[len] == '\"')
		{
			while (str[len + 1] != '\"')
				len++;
			len++;
		}
		len++;
	}
	return (len);
}
