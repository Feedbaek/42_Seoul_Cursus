/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:00:37 by sungmcho          #+#    #+#             */
/*   Updated: 2022/04/05 21:11:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	set_fd(int mode, char **redir, char	*filename)
{
	int	fd;

	if (!filename)
	{
		ft_putendl_fd("bash: syntax error near unexpected token 'newline'", 2);
		return (-1);
	}
	if (mode == 2 || mode == 4)
	{
		fd = open(filename, O_CREAT, 0644);
		close(fd);
	}
	if (*redir)
		free(*redir);
	*redir = ft_strdup(filename);
	return (1);
}

static void	join_free(char **src, char *s, char **b_p, bool quote)
{
	char	*temp;
	char	*temp2;

	temp = (char *)malloc(s - *b_p + 1);
	if (!temp)
		exit(EXIT_FAILURE);
	ft_strlcpy(temp, *b_p, s - *b_p + 1);
	if (!quote)
		process_env_var(&temp);
	if (*src)
	{
		temp2 = ft_strjoin(*src, temp);
		free(*src);
		free(temp);
		temp = temp2;
	}
	*src = temp;
	*b_p = NULL;
}

void	process_str(char *s, char **res)
{
	bool	quotes[2];
	char	*b_p;

	quotes[0] = false;
	quotes[1] = false;
	b_p = NULL;
	while (*s)
	{
		if (!b_p)
			b_p = s;
		if (*s == '\'' && !quotes[1])
		{
			join_free(res, s, &b_p, quotes[0]);
			quotes[0] = !quotes[0];
		}
		if (*s == '"' && !quotes[0])
		{
			join_free(res, s, &b_p, quotes[0]);
			quotes[1] = !quotes[1];
		}
		s++;
	}
	if (b_p)
		join_free(res, s, &b_p, quotes[0]);
}

void	add_arg(t_cmd *x, char **arg)
{
	int		i;
	int		len;
	char	**temp;

	i = -1;
	len = two_ptr_counter(x->argv);
	temp = (char **)malloc((len + 2) * sizeof(char *));
	if (!temp)
		malloc_error();
	if (x->argv)
	{
		while ((x->argv)[++i])
			temp[i] = (x->argv)[i];
		temp[i++] = *arg;
		temp[i] = NULL;
		free(x->argv);
	}
	else
	{
		temp[++i] = *arg;
		temp[++i] = NULL;
	}
	if (!len)
		path_finder(g_state.envp, x, *arg);
	x->argv = temp;
}
