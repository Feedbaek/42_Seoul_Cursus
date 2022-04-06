/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:01:03 by sungmcho          #+#    #+#             */
/*   Updated: 2022/04/06 19:20:45 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_env(void)
{
	int	i;
	int	len;

	i = -1;
	while (g_state.envp[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(g_state.envp[i], 1);
	}
}

static int	check(char *s, char *export)
{
	int	i;

	i = 0;
	if (!s || *export == '=' || (s[i] != '_' && !ft_isalpha(s[i])))
	{
		ft_putstr_fd("bash: export: `", 2);
		ft_putstr_fd(export, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		return (0);
	}
	i++;
	while (s[i])
	{
		if (s[i] != '_' && !ft_isalnum(s[i]))
		{
			ft_putstr_fd("bash: export: `", 2);
			ft_putstr_fd(export, 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_export(char **s, int flag)
{
	char	**split;
	int		i;

	i = 0;
	if (two_ptr_counter(s) == 1)
		print_env();
	else
	{
		while (s[++i])
		{
			split = ft_split(s[i], '=');
			if (!split)
				malloc_error();
			if (check(split[0], s[i]))
				do_export(split[0], s[i]);
			free_double_pointer(&split);
		}
	}
	g_state.exit_status = 0;
	if (flag)
		exit(0);
}
