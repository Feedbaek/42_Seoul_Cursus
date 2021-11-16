/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:29:59 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/08 21:52:44 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_backslash(t_state *s)
{
	int		flag;
	int		i;
	char	*str;

	if (s->input == 0 || ft_strlen(s->input) == 0)
		return (0);
	str = s->input;
	flag = -1;
	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == '\\' && i >= 0)
	{
		flag *= -1;
		i--;
	}
	if (flag == 1)
	{
		s->input = delete_last_char(str);
		return (1);
	}
	else
		return (0);
}

void	handle_eof(t_state *s, char *input)
{
	if (!input)
	{
		printf("exit\n");
		g_state.exit_status = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, &s->t.save);
		exit(g_state.exit_status);
	}
}

void	prompt2(t_state *s)
{
	write(1, "bash", 4);
	init_term(s);
	while (1)
	{
		write(1, "> ", 2);
		if (term_loop(s) == 0)
		{
			save_history(s);
			reset_save(s);
			if (g_state.input)
				g_state.input2 = ft_strdup(g_state.input);
			break ;
		}
		else
			continue ;
	}
}

void	prompt3(t_state *s)
{
	write(1, "> ", 2);
	init_term(s);
	while (1)
	{
		if (term_loop(s) == 0)
		{
			reset_save(s);
			if (g_state.input)
				g_state.input2 = ft_strdup(g_state.input);
			break ;
		}
		else
			continue ;
	}
}
