/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:40:28 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 14:48:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	cnt_collect(t_game *game)
{
	int row;
	int col;

	row = 0;
	game->param.num_collect = 0;
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 'C')
				game->param.num_collect++;
			col++;
		}
		row++;
	}
}

void	set_map(t_game *game)
{
	cnt_collect(game);
}
