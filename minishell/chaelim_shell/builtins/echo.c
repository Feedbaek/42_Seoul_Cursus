/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:27:24 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 16:40:15 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*echo_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*tmp;
	char	*tmp_s1;
	int		space;

	if (!*s1)
		space = 0;
	else
		space = 1;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) \
				+ 1 + space) * sizeof(char));
	tmp = result;
	tmp_s1 = s1;
	if (!result)
		print_malloc_error();
	while (*s1)
		*(result++) = *(s1++);
	if (space)
		*(result++) = ' ';
	while (*s2)
		*(result++) = *(s2++);
	*result = 0;
	free(tmp_s1);
	return (tmp);
}

int	check_n(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (*(str++) != '-')
		return (0);
	while (*str == 'n')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

void	ft_echo(t_cmd *cmd)
{
	int		i;
	int		nflag;
	char	*str;

	nflag = check_n((cmd->cmdlines)[1]);
	i = 1;
	if (nflag)
		i = 2;
	str = (char *)malloc(sizeof(char));
	if (!str)
		print_malloc_error();
	*str = 0;
	while ((cmd->cmdlines)[i])
	{
		str = echo_strjoin(str, (cmd->cmdlines)[i]);
		i++;
	}
	ft_putstr_fd(str, STDOUT);
	if (!nflag)
		write(1, "\n", 1);
	free(str);
	g_state.exit_status = 0;
}
