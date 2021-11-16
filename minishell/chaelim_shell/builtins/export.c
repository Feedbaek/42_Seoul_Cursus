/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:27:31 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 00:42:20 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_key(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (ft_isalpha(str[i]) || str[i] == '_')
	{
		while (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		if ((str[i] == '=' || str[i] == 0) && i != 0)
		{
			line = (char *)malloc(sizeof(char) * (i + 1));
			i = 0;
			while ((str[i] != '=') && (str[i] != 0))
			{
				line[i] = str[i];
				i++;
			}
			line[i] = 0;
			return (line);
		}
	}
	print_exec_error_3("export", str, "not a valid identifier");
	g_state.exit_status = 1;
	return (0);
}

void	export_print(void)
{
	char	*key;
	char	*value;
	t_list	*cur;

	cur = g_state.export->next;
	while (cur)
	{
		if (**(cur->content))
		{
			key = find_key(*(cur->content));
			value = find_value(key);
			ft_putstr_fd("declare -x ", STDOUT);
			ft_putstr_fd(key, STDOUT);
			if (value)
			{
				ft_putstr_fd("=\"", STDOUT);
				ft_putstr_fd(value, STDOUT);
				ft_putchar_fd('"', STDOUT);
			}
			free(key);
			ft_putchar_fd('\n', STDOUT);
		}
		cur = cur->next;
	}
}

void	add_envp_2(char **new, t_list *tmp_list, char *str, int end)
{
	t_list	*tlist;
	t_list	*blist;

	new[end] = ft_strdup(str);
	set_export(tmp_list, &(new[end]));
	new[end + 1] = 0;
	free(g_state.envp);
	tlist = g_state.export;
	free(tlist->content);
	while (tlist)
	{
		blist = tlist;
		tlist = tlist->next;
		free(blist);
	}
	g_state.envp = new;
	g_state.export = tmp_list;
}

void	add_envp(char *str)
{
	int		j;
	char	**new;
	char	*tmp;
	t_list	*tmp_list;

	j = 0;
	while (g_state.envp[j])
		j++;
	new = (char **)malloc(sizeof(char *) * (j + 2));
	if (!new)
		print_malloc_error();
	j = -1;
	tmp = (char *)malloc(sizeof(char));
	if (!tmp)
		print_malloc_error();
	*tmp = 0;
	tmp_list = ft_lstnew(tmp);
	while (g_state.envp[++j])
	{
		new[j] = g_state.envp[j];
		set_export(tmp_list, &(new[j]));
	}
	add_envp_2(new, tmp_list, str, j);
}

void	ft_export(t_cmd *cmd)
{
	int		i;
	char	*tmp;
	char	*str;

	g_state.exit_status = 0;
	i = 1;
	if ((cmd->cmdlines)[i] == 0)
		export_print();
	else
	{
		while ((cmd->cmdlines)[i])
		{
			tmp = find_key((cmd->cmdlines)[i]);
			if (!tmp)
				return ;
			str = ft_strdup(cmd->cmdlines[i]);
			if (!ft_change_env(tmp, str))
			{
				free(str);
				add_envp((cmd->cmdlines)[i]);
			}
			free(tmp);
			i++;
		}
	}
}
