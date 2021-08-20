/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:57:13 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 20:14:57 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	map_parse(t_game *game, char *file)
{
	int		fd;
	int		status;
	int		size;
	char	**arr_str;
	char	**new_arr_str;

	size = 0;
	status = 1;
	fd = open(file, O_RDONLY);
	arr_str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr_str || fd < 0)
		exit_so_long("malloc or open");
	arr_str[0] = 0;
	while (status == 1)
	{
		status = get_next_line(fd, &arr_str[size++]);
		new_arr_str = (char **)malloc(sizeof(char *) * size + 1);
		if (status == -1 || !new_arr_str)
			exit_so_long("malloc or gnl");
		ft_memcpy(new_arr_str, arr_str, sizeof(char *) * size);
		new_arr_str[size] = 0;
		free(arr_str);
		arr_str = new_arr_str;
	}
	game->map = arr_str;
	close(fd);
}
