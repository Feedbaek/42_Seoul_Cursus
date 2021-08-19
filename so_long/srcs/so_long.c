/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:42:34 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/19 00:21:47 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <string.h>

void	minilibx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Welcome So_long");
}

void	img_init(t_game	*game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
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
				game->img.data[(tile_row + row) * HEIGHT + col + tile_col] = 0xb3b3b3;
			else
				game->img.data[(tile_row + row) * HEIGHT + col + tile_col] = 0xFFFFFF;
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
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 1)
				draw_pixels_of_tile(game, row, col);
			col++;
		}
		row++;
	}
}

void	map_init(t_game *game)
{
	int src[ROW][COL] = {
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1}
	//{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	//{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	//{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	//{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	//{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	//{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	//{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	//{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	//{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	//{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	//{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	//{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	//{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	//{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	//{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	memcpy(game->map, src, sizeof(int) * ROW * COL);
	draw_tiles(game);
}

int	main(void)
{
	t_game	game;
	//t_img	img;
	t_param	param;

	minilibx_init(&game);
	img_init(&game);
	map_init(&game);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 0, 0);
	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(game.mlx_ptr);
	return (0);
	//mlx.mlx_ptr = mlx_init();
	//mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 600, "mlx 42");
	//param_init(&param);
	//img.img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "./img/test.xpm", &img.width, &img.height);
	//// 사진 정보 width: 3584, height: 2240
	////img.img_ptr = mlx_new_image(mlx.mlx_ptr, 400, 300);
	//img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	//count_h = -1;
	//while (++count_h < img.height)
	//{
	//	count_w = -1;
	//	while (++count_w < (img.width / 2))
	//	{
	//		if (count_w % 2)
	//			img.data[count_h * img.width + count_w] = 0xFFFFFF;
	//		else
	//			img.data[count_h * img.width + count_w] = 0xFF0000;
	//	}
	//}
	//mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
}
