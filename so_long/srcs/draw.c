/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:53:54 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 18:27:49 by minskim2         ###   ########.fr       */
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
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, col, row);
}

void	draw_object(t_game *game)
{
	int row;
	int col;

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
			col++;
		}
		row++;
	}
	put_object(game, game->param.y, game->param.x, "./img/player.xpm");
}

void	draw_pixels_of_tile(t_game *game, int row, int col)
{
	int	tile_row;
	int	tile_col;

	row *= TILE_SIZE;
	col *= TILE_SIZE;
	tile_row = 0;
	while (tile_row < TILE_SIZE)
	{
		tile_col = 0;
		while (tile_col < TILE_SIZE)
		{
			if (tile_row == TILE_SIZE - 1 || tile_col == TILE_SIZE - 1)
				game->img.data[(tile_row + row) * game->param.col * TILE_SIZE + col + tile_col] = 0xb3b3b3;
			else
				game->img.data[(tile_row + row) * game->param.col * TILE_SIZE + col + tile_col] = 0xFFFFFF;
			tile_col++;
		}
		tile_row++;
	}
}

void	draw_tiles(t_game *game)
{
	int row;
	int col;

	row = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (col < game->param.col)
		{
			if (game->map[row][col] == '1')
				draw_pixels_of_tile(game, row, col);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
}
