/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:49:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/20 14:55:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_press(int key, t_game *game)
{
	if (key == KEY_W && game->map[game->param.y-1][game->param.x] != '1')
		game->param.y--;
	else if (key == KEY_S && game->map[game->param.y+1][game->param.x] != '1')
		game->param.y++;
	else if (key == KEY_D && game->map[game->param.y][game->param.x+1] != '1')
		game->param.x++;
	else if (key == KEY_A && game->map[game->param.y][game->param.x-1] != '1')
		game->param.x--;
	else if (key == KEY_ESC)
	{
		printf("close");
		exit(0);
	}
	search_map(game);
	draw_tiles(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, 0, 0);
	draw_object(game);
	return (0);
}

int	exit_click(void)
{
	printf("close");
	exit(0);
}
