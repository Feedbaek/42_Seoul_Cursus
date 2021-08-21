/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:57:13 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/21 20:08:59 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	int	set_open(int *idx, char *file)
{
	int	fd;

	*idx = 0;
	fd = open(file, O_RDONLY);
	return (fd);
}

static	char	**gnl(int fd, int idx, char **arr_str)
{
	char	**new_arr_str;
	char	*tmp;
	int		status;

	status = get_next_line(fd, &tmp);
	while (status == 1)
	{
		new_arr_str = (char **)malloc(sizeof(char *) * (idx + 2));
		if (!new_arr_str)
			exit_so_long("malloc");
		ft_memcpy(new_arr_str, arr_str, sizeof(char *) * idx);
		new_arr_str[idx] = tmp;
		new_arr_str[++idx] = 0;
		free(arr_str);
		arr_str = new_arr_str;
		status = get_next_line(fd, &tmp);
	}
	if (status == -1)
		exit_so_long("gnl");
	free(tmp);
	return (arr_str);
}

void	map_parse(t_game *game, char *file)
{
	int		fd;
	int		idx;
	char	**arr_str;

	fd = set_open(&idx, file);
	arr_str = (char **)malloc(sizeof(char *) * (idx + 1));
	if (!arr_str || fd < 0)
		exit_so_long("malloc or open");
	arr_str[0] = 0;
	game->map = gnl(fd, idx, arr_str);
	close(fd);
}
