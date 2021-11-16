/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:11:12 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 21:16:13 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	use_temp(t_cmd *cmd, int fd, int i)
{
	char	*input;

	if (g_state.input != 0)
	{
		if (i == cmd->dinput->index - 1)
		{
			input = make_str(g_state.input);
			ft_putendl_fd(input, fd);
			free(input);
		}
		if (ft_strncmp(g_state.input, cmd->dinput->inputs[i], \
		ft_strlen(cmd->dinput->inputs[i]) + 1) == 0)
			i += 1;
	}
	else if (i == cmd->dinput->index)
		ft_putendl_fd("", fd);
	return (i);
}

char	*make_str(char *str)
{
	char	*new;
	char	*re;
	int		len;

	new = ft_strdup("");
	len = -1;
	while (str[++len])
	{
		if (str[len] == '$')
		{
			re = 0;
			str[len] = 0;
			new = ft_strjoin1(new, str);
			str += len;
			str += find_var(str, &re) + 1;
			new = ft_strjoin2(new, re);
			len = -1;
		}
	}
	new = ft_strjoin1(new, str);
	return (new);
}
