/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:53:54 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/22 14:59:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_object(t_game *game, int row, int col, char *path)
{
	int		width;
	int		height;
	void	*img_ptr;

	row *= TILE_SIZE;
	col *= TILE_SIZE;
	img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!img_ptr)
		exit_so_long("put_object");
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, col, row);
}

void	draw_object(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (col < game->param.col)
		{
			if (game->map[row][col] == 'C')
				put_object(game, row, col, "./img/collectible.xpm");
			else if (game->map[row][col] == 'E')
				put_object(game, row, col, "./img/exit.xpm");
			else if (game->map[row][col] == '1')
				put_object(game, row, col, "./img/wall.xpm");
			col++;
		}
		row++;
	}
	put_object(game, game->param.y, game->param.x, "./img/player.xpm");
}
