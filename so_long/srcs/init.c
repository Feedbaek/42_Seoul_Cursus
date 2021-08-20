/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:47:24 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 14:34:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

void	location_init(t_game *game)
{
	int row;
	int col;

	row = 0;
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 'P')
			{
				game->param.x = col;
				game->param.y = row;
				return ;
			}
			col++;
		}
		row++;
	}
	put_object(game, game->param.y, game->param.x, "./img/player.xpm");
}

void	map_init(t_game *game)
{
	char src[ROW][COL] = {
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', 'P', '1', '0', '1', '0', '0', '0', 'C', '1', '0', '1', '0', '0', '1'},
	{'1', '0', 'C', '0', '0', '1', '0', '1', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '0', '1', '1', '0', '0', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '1', 'C', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', 'C', '0', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1'},
	{'1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '1', 'C', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', 'E', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};

	ft_memcpy(game->map, src, sizeof(char) * ROW * COL);
	draw_tiles(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
	location_init(game);
	draw_object(game);
}
