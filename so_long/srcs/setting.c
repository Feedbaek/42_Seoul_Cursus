/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:40:28 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 18:38:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	cnt_collect(t_game *game)
{
	int row;
	int col;

	row = 0;
	game->param.num_collect = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (col < game->param.col)
		{
			if (game->map[row][col] == 'C')
				game->param.num_collect++;
			col++;
		}
		row++;
	}
}

void	cnt_mapsize(t_game *game)
{
	int		cnt;
	char	**parse_row;
	char	*parse_col;

	cnt = 0;
	parse_row = game->map;
	parse_col = *game->map;
	while (*parse_row)
	{
		cnt++;
		parse_row++;
	}
	game->param.row = cnt;
	cnt = 0;
	while (*parse_col)
	{
		cnt++;
		parse_col++;
	}
	game->param.col = cnt;
}

void	set_map(t_game *game)
{
	cnt_mapsize(game);
	cnt_collect(game);
}
