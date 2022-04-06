/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:12:09 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 18:55:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_cmds(t_cmd **head)
{
	t_cmd	*temp;
	t_cmd	*tab;

	tab = *head;
	while (tab)
	{
		if (tab->cmd)
			free(tab->cmd);
		if (tab->argv)
			free_double_pointer(&tab->argv);
		if (tab->path)
			free_double_pointer(&tab->path);
		if (tab->limiter)
			free(tab->limiter);
		if (tab->redirect_in)
			free(tab->redirect_in);
		if (tab->redirect_out)
			free(tab->redirect_out);
		if (tab->redirect_out_add)
			free(tab->redirect_out_add);
		temp = tab->next;
		free(tab);
		tab = temp;
	}
}

static int	check_back_col(char *s)
{
	while (*s)
	{
		if (*s == '\\' || *s == ';')
		{
			ft_putendl_fd("We don't interrupt \\ or ;", STDERR_FILENO);
			return (1);
		}
		s++;
	}
	return (0);
}

static int	check_quote(char *s)
{
	int	num_quotes;
	int	num_dquotes;

	num_quotes = 0;
	num_dquotes = 0;
	while (*s)
	{
		if (*s == '\'')
			num_quotes++;
		if (*s == '"')
			num_dquotes++;
		s++;
	}
	if (num_quotes % 2 != 0 || num_dquotes % 2 != 0)
	{
		ft_putendl_fd("We don't interrupt unclosed quotes.", STDERR_FILENO);
		return (1);
	}
	return (0);
}

static int	checker(char *str)
{
	return (!check_back_col(str) && !check_quote(str) \
	&& ft_strncmp(str, "\n", ft_strlen(str)));
}

void	print_prompt(void)
{
	char	*str;
	t_cmd	*head;

	while (1)
	{
		str = readline("bash$ ");
		if (str)
		{
			if (checker(str))
			{
				parser(str, &head);
				execute_func(head);
				free_cmds(&head);
			}
			if (ft_strncmp(str, "\n", ft_strlen(str)))
				add_history(str);
			free(str);
			str = NULL;
		}
		else
		{
			ft_putendl_fd("\033[1A\033[5C exit", 1);
			break ;
		}
	}
}
