/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:12:41 by sungmcho          #+#    #+#             */
/*   Updated: 2022/04/05 17:57:14 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_isnumeric(char *s)
{
	while (*s)
	{
		if ('0' > *s || *s > '9')
			return (-1);
		s++;
	}
	return (0);
}

static void	exit_w_code(int i)
{
	ft_putendl_fd("exit", 1);
	exit(i);
}

void	ft_exit(char **s, int flag)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i == 1)
		exit_w_code(0);
	else if (i == 2)
	{
		g_state.exit_status = ft_isnumeric(s[1]);
		if (g_state.exit_status == -1)
		{
			ft_putstr_fd("exit: ", 1);
			ft_putstr_fd(s[1], 1);
			ft_putendl_fd(": numeric argument required", 1);
			exit(0);
		}
		exit_w_code(ft_atoi(s[1]));
	}
	else
		ft_putendl_fd("exit: too many arguments", 1);
	if (flag)
		exit(0);
}
