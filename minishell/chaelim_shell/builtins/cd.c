/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:43:13 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 00:42:18 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_pwds(char *oldpwd)
{
	char	*pwd;
	char	*tmp;

	tmp = getcwd(0, MAXSIZE);
	pwd = ft_strjoin("PWD=", tmp);
	free(tmp);
	ft_change_env("PWD", pwd);
	ft_change_env("OLDPWD", oldpwd);
}

void	cd_home(char *oldpwd)
{
	char	*home;

	home = find_value("HOME");
	if (chdir(home) == -1)
	{
		print_exec_error_2("cd", "HOME not set");
		g_state.exit_status = 1;
	}
	else
		change_pwds(oldpwd);
}

void	ft_cd(t_cmd *cmd)
{
	char	*path;
	char	*oldpwd;

	g_state.exit_status = 0;
	path = getcwd(0, MAXSIZE);
	oldpwd = ft_strjoin("OLDPWD=", path);
	free(path);
	path = (cmd->cmdlines)[1];
	if (path == NULL || !ft_strncmp("~", path, 2) || *path == 0)
		cd_home(oldpwd);
	else
	{
		if (chdir(path) == -1)
		{
			print_exec_error_3("cd", path, "No such file or directory");
			free(oldpwd);
			g_state.exit_status = 1;
		}
		else
			change_pwds(oldpwd);
	}
}
