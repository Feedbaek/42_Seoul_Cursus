/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:27:33 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 16:47:43 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_unset(char *str)
{
	char	*tmp;

	tmp = str;
	if (ft_isalpha(*tmp) || *tmp == '_')
		tmp++;
	while (ft_isalnum(*tmp) || *tmp == '_')
		tmp++;
	if (*tmp != 0)
	{
		print_exec_error_3("unset", str, "not a valid identifier");
		g_state.exit_status = 1;
		return (0);
	}
	return (1);
}

void	ft_unset(t_cmd *cmd)
{
	int		i;
	char	*empty;

	i = 1;
	g_state.exit_status = 0;
	if ((cmd->cmdlines)[i] == 0)
		return ;
	while ((cmd->cmdlines)[i])
	{
		if (is_valid_unset((cmd->cmdlines)[i]))
		{
			empty = (char *)malloc(sizeof(char));
			*empty = 0;
			if (!ft_change_env((cmd->cmdlines)[i], empty))
				free(empty);
		}
		i++;
	}
}
