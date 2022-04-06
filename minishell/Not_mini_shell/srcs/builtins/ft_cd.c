/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:48:56 by sungmcho          #+#    #+#             */
/*   Updated: 2022/04/05 18:04:37 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_cd_error(char *s, char *err)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
	g_state.exit_status = 1;
}

int	get_envp_idx(char **envp, char *s)
{
	int		i;
	char	**temp;

	i = 0;
	while (envp[i])
	{
		temp = ft_split(envp[i], '=');
		if (!temp)
			malloc_error();
		if (equals(temp[0], s))
		{
			free_double_pointer(&temp);
			return (i);
		}
		free_double_pointer(&temp);
		i++;
	}
	return (-1);
}

static void	store_pwd(char *s)
{
	char	*val;

	if (!s)
	{
		s = getcwd(s, BUFSIZ);
		val = ft_strjoin("PWD=", s);
		free(s);
	}
	else
		val = ft_strjoin("PWD=", s);
	do_export("PWD", val);
	free(val);
}

static void	cd_home(int home_idx)
{
	char	**temp;

	if (home_idx < 0)
		print_cd_error("HOME", "HOME not set");
	else
	{
		temp = ft_split(g_state.envp[home_idx], '=');
		if (!temp)
			malloc_error();
		if (chdir(temp[1]) == -1)
			print_cd_error("HOME", strerror(errno));
		store_pwd(temp[1]);
		free_double_pointer(&temp);
	}
}

void	ft_cd(char **s, int flag)
{
	int		home_idx;

	g_state.exit_status = 0;
	home_idx = get_envp_idx(g_state.envp, "HOME");
	if (s[1])
	{
		if (chdir(s[1]) == -1)
			print_cd_error(s[1], strerror(errno));
		else
			store_pwd(NULL);
	}
	else
		cd_home(home_idx);
	if (flag)
		exit(0);
}
