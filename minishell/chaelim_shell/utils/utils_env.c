/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 06:26:29 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 16:46:41 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwdcmp(char *str1, char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while ((*s1 == *s2) && (*s1 != '=') && (*s2 != '=') && s1 && s2)
	{
		s1++;
		s2++;
	}
	if (*s2 == '=')
		return (1);
	else if (*s1 == '=')
		return (-1);
	else if (*s1 > *s2)
		return (1);
	else if (*s1 < *s2)
		return (-1);
	else
		return (0);
}

void	set_export(t_list *target, char **content)
{
	t_list	*cur_list;
	t_list	*new_list;

	new_list = ft_lstnew(content);
	if (!new_list)
		print_malloc_error();
	cur_list = target;
	while (cur_list->next)
	{
		if (ft_pwdcmp(*content, *(cur_list->next->content)) < 0)
			break ;
		cur_list = cur_list->next;
	}
	if (cur_list->next && (ft_pwdcmp(*content, *(cur_list->next->content)) > 0))
		cur_list->next->next = new_list;
	else
	{
		new_list->next = cur_list->next;
		cur_list->next = new_list;
	}
}

void	set_env_export(char **envs)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char));
	if (!str)
		print_malloc_error();
	*str = 0;
	while (envs[i])
		i++;
	g_state.envp = malloc(sizeof(char *) * (i + 1));
	if (!g_state.envp)
		print_malloc_error();
	i = 0;
	g_state.export = ft_lstnew(str);
	while (envs[i])
	{
		g_state.envp[i] = ft_strdup(envs[i]);
		if (!g_state.envp[i])
			print_malloc_error();
		set_export(g_state.export, &(g_state.envp[i]));
		i++;
	}
	g_state.envp[i] = 0;
}

char	*find_value(char *key)
{
	int		i;
	int		length;
	char	*line;

	i = 0;
	line = ft_strjoin(key, "=");
	length = ft_strlen(line);
	while ((g_state.envp)[i])
	{
		if (!ft_strncmp(line, (g_state.envp)[i], length))
		{
			free(line);
			return ((g_state.envp)[i] + length);
		}
		i++;
	}
	free(line);
	return (0);
}

int	ft_change_env(char *key, char *str)
{
	int		i;

	if (!key)
		return (0);
	i = 0;
	while (g_state.envp[i])
	{
		if (!ft_strncmp(key, g_state.envp[i], ft_strlen(key)))
		{
			if (*str == 0 || str[ft_strlen(key)] == '=')
			{
				free(g_state.envp[i]);
				g_state.envp[i] = str;
				return (1);
			}
			if (str[ft_strlen(key)] == 0 && (g_state.envp[i][ft_strlen(key) \
			+ 1] == 0 || g_state.envp[i][ft_strlen(key)] == '='))
				return (1);
		}
		i++;
	}
	return (0);
}
