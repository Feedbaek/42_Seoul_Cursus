/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:10:14 by sungmcho          #+#    #+#             */
/*   Updated: 2022/04/05 21:12:53 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	init_struct(t_cmd **x)
{
	t_cmd	*temp;

	temp = *x;
	temp->idx = 0;
	temp->pid = 0;
	temp->status = 0;
	temp->cmd = NULL;
	temp->argv = NULL;
	temp->path = NULL;
	temp->envp = NULL;
	temp->limiter = NULL;
	temp->redirect_in = NULL;
	temp->redirect_out = NULL;
	temp->redirect_out_add = NULL;
	temp->next = NULL;
}

static int	check_redir(char *s1, char *s2, t_cmd *x)
{
	int	ret;

	ret = 0;
	if (equals(s1, "<"))
		ret = set_fd(1, &(x->redirect_in), s2);
	else if (equals(s1, ">"))
		ret = set_fd(2, &(x->redirect_out), s2);
	else if (equals(s1, "<<"))
		ret = (set_fd(3, &(x->limiter), s2));
	else if (equals(s1, ">>"))
		ret = (set_fd(4, &(x->redirect_out_add), s2));
	else
		ret = 0;
	return (ret);
}

static void	cmd_init(char *s, t_cmd *x)
{
	int		i;
	int		fd_checker;
	char	**temp;
	char	*p_s;

	temp = parse_split(s, ' ');
	if (!temp)
		malloc_error();
	i = -1;
	while (temp[++i])
	{
		fd_checker = check_redir(temp[i], temp[i + 1], x);
		if (fd_checker < 0)
			break ;
		else if (fd_checker == 1)
			i += fd_checker;
		else
		{
			p_s = NULL;
			process_str(temp[i], &p_s);
			add_arg(x, &p_s);
		}
	}
	free_double_pointer(&temp);
}

static void	set_cmds(char **splited_w_vb, int len, t_cmd **head)
{
	int		i;
	t_cmd	*cmd_arg;
	t_cmd	*prev_cmd;

	i = 0;
	while (i < len)
	{
		cmd_arg = malloc(sizeof(t_cmd));
		if (!cmd_arg)
			exit(1);
		init_struct(&cmd_arg);
		if (i == 0)
		{
			*head = cmd_arg;
			prev_cmd = cmd_arg;
		}
		else
		{
			prev_cmd->next = cmd_arg;
			prev_cmd = cmd_arg;
		}
		cmd_init(splited_w_vb[i], cmd_arg);
		cmd_arg->idx = i;
		i++;
	}
}

void	parser(char *s, t_cmd **head)
{
	int			len;
	char		**splited_w_vb;

	splited_w_vb = parse_split(s, '|');
	if (!splited_w_vb)
		malloc_error();
	len = two_ptr_counter(splited_w_vb);
	set_cmds(splited_w_vb, len, head);
	free_double_pointer(&splited_w_vb);
}
