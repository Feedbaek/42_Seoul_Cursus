/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:48:23 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:20:36 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nl_in_backup(const char *backup)
{
	int		i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	split_backup(char **backup, char **line, int idx_nl)
{
	char	*tmp;

	(*backup)[idx_nl] = '\0';
	*line = ft_strdup(*backup);
	tmp = ft_strdup(&(*backup)[idx_nl + 1]);
	free(*backup);
	*backup = tmp;
}

static int	split_remainder(char **backup, char **line)
{
	int		idx_nl;

	if (!(*backup))
	{
		*line = ft_strdup("");
		return (0);
	}
	idx_nl = nl_in_backup(*backup);
	if (idx_nl >= 0)
	{
		split_backup(backup, line, idx_nl);
		return (1);
	}
	*line = ft_strdup(*backup);
	free(*backup);
	*backup = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*backup;
	ssize_t			read_size;
	int				idx_nl;

	if ((fd < 0) || (fd > OPEN_MAX) || (!line) || (BUFFER_SIZE <= 0))
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		backup = ft_strjoin(backup, buf);
		idx_nl = nl_in_backup(backup);
		if (idx_nl >= 0)
		{
			split_backup(&backup, line, idx_nl);
			return (1);
		}
	}
	if (read_size == -1)
		return (-1);
	return (split_remainder(&backup, line));
}
