#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int free_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (0);
}

int fatal(char **cmd, int err)
{
	char *str;
	if (err == 1)
		str = "error: fatal";
	if (err == 2)
		str = "error: cd: bad arguments";
	if (err == 3)
		str = "error: cd: cannot change directory to ";
	if (err == 4)
		str = "error: cannot execute ";
	write(STDERR_FILENO, str, ft_strlen(str));
	if (err == 3)
		write(STDERR_FILENO, cmd[1], ft_strlen(cmd[1]));
	if (err == 4)
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
	write(STDERR_FILENO, "\n", 1);
	if (cmd)
		return (free_tab(cmd));
	return (0);
}

int bultin_cd(char **cmd)
{
	if (!cmd[1] || cmd[2])
		return (fatal(cmd, 2));
	if (chdir(cmd[1]) < 0)
		return (fatal(cmd, 3));
	return (1);
}

char **parse_cmd(char **arg, int *i, char *c, int *last)
{
	int a = *i;
	char **cmd =NULL;
	int x = 0;
	int y = 0;

	*last = 0;
	while (arg[a] && (strcmp(arg[a], c) != 0))
		a++;
	if (!arg[a])
		*last = 1;
	if (!(cmd = (char**)malloc(sizeof(char*) * ((a - *i) + 1))))
		return NULL;
	while (*i < a)
	{
		y = 0;
		if (!(cmd[x] = (char*)malloc(sizeof(char) * ft_strlen(arg[*i]) + 1)))
			return NULL;
		while (y < ft_strlen(arg[*i]))
		{
			cmd[x][y] = arg[*i][y];
			y++;
		}
		cmd[x][y] = '\0';
		x++;
		(*i)++;
	}
	cmd[x] = NULL;
	if (arg[*i] && arg[*i + 1])
		(*i)++;
	return (cmd);
}

int check_exec_cmd(char **cmd, char **env)
{
	int fdp[2];
	int fd_in;
	int status;
	int last;
	int count;
	pid_t pid;
	int a = 0;
	char **tmp = NULL;

	if ((fd_in = dup(STDIN_FILENO)) < 0)
		return (fatal(cmd, 1));
	while (cmd[a])
	{
		if (strcmp(cmd[a], "cd") == 0)
			return (bultin_cd(cmd));
		if (!(tmp = parse_cmd(cmd, &a, "|", &last)))
			return (fatal(cmd, 1));
		count++;
		if (pipe(fdp) < 0 || (pid = fork()) < 0)
		{
			free_tab(cmd);
			exit(fatal(tmp, 1));
		}
		if (pid == 0)
		{
			if (dup2(fd_in, STDIN_FILENO) < 0)
			{
				free_tab(cmd);
				exit(fatal(tmp, 1));
			}
			if (last == 0)
			{
				if (dup2(fdp[1], STDOUT_FILENO) < 0)
				{
					free_tab(cmd);
					exit(fatal(tmp, 1));
				}
			}
			close(fdp[0]);
			close(fdp[1]);
			close(fd_in);
			if (execve(tmp[0], tmp, env) < 0)
			{
				free_tab(cmd);
				exit(fatal(tmp, 4));
			}
		}
		if (dup2(fdp[0], fd_in) < 0)
		{
			free_tab(cmd);
			exit(fatal(tmp, 1));
		}
		free_tab(tmp);
		close(fd_in);
	}
	a = 0;
	while(a < count)
	{
		waitpid(-1, &status, 0);
		a++;
	}
	return (1);
}

int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	int i = 1;
	int last = 0;

	while (i < ac) {
		if (!(cmd = parse_cmd(av, &i, ";", &last)))
			return (fatal(cmd,1));
		if (!(check_exec_cmd(cmd, env)))
			return (1);
	}
	return (0);
}
