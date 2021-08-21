/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:40:28 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/21 21:02:04 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	set_cnt_object(t_game *game)
{
	game->param.row = 0;
	game->param.col = 0;
	game->param.num_collect = 0;
	game->param.num_player = 0;
	game->param.num_exit = 0;
	game->param.col = ft_strlen(*(game->map));
}

static	void	cnt_object(t_game *game)
{
	int		cnt;
	char	**parse_row;

	set_cnt_object(game);
	parse_row = game->map;
	while (*parse_row)
	{
		cnt = 0;
		while ((*parse_row)[cnt])
		{
			if ((*parse_row)[cnt] == 'C')
				game->param.num_collect++;
			else if ((*parse_row)[cnt] == 'P')
				game->param.num_player++;
			else if ((*parse_row)[cnt] == 'E')
				game->param.num_exit++;
			else if ((*parse_row)[cnt] != '0' && (*parse_row)[cnt] != '1')
				exit_so_long("invalid map");
			cnt++;
		}
		if (cnt != game->param.col)
			exit_so_long("invalid map");
		parse_row++;
		game->param.row++;
	}
}

static	void	check_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->param.col)
	{
		if (game->map[0][i] != '1' || game->map[game->param.row - 1][i] != '1')
			exit_so_long("invalid map");
		i++;
	}
	i = 0;
	while (i < game->param.row)
	{
		if (game->map[i][0] != '1' || game->map[i][game->param.col - 1] != '1')
			exit_so_long("invalid map");
		i++;
	}
}

void	set_map(t_game *game)
{
	cnt_object(game);
	if (game->param.num_collect < 1 || game->param.num_exit < 1
		|| game->param.num_player != 1)
		exit_so_long("invalid map");
	check_map(game);
}
