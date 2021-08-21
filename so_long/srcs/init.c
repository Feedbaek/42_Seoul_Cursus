/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:47:24 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/21 21:50:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	minilibx_init(t_game *game, char *file)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_so_long("mlx_init");
	map_parse(game, file);
	set_map(game);
	game->param.walk = 0;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->param.col * TILE_SIZE,
			game->param.row * TILE_SIZE, "Welcome So_long");
	if (!game->win_ptr)
		exit_so_long("mlx_new_window");
}

void	img_init(t_game	*game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr,
			game->param.col * TILE_SIZE, game->param.row * TILE_SIZE);
	if (!game->img.img_ptr)
		exit_so_long("mlx_new_image");
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	if (!game->img.data)
		exit_so_long("mlx_get_data_addr");
}

void	location_init(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->param.row)
	{
		col = 0;
		while (col < game->param.col)
		{
			if (game->map[row][col] == 'P')
			{
				game->param.x = col;
				game->param.y = row;
				put_object(game, game->param.y, game->param.x, "./img/player.xpm");
				return ;
			}
			col++;
		}
		row++;
	}
}

void	map_init(t_game *game)
{
	draw_tiles(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.img_ptr, 0, 0);
	location_init(game);
	draw_object(game);
}
