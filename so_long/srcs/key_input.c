/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:49:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/22 14:59:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	when_walk(int *loc, int value, int *walk)
{
	*loc += value;
	*walk += 1;
	printf("walk: %d\n", *walk);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_W && game->map[game->param.y - 1][game->param.x] != '1')
		when_walk(&game->param.y, -1, &game->param.walk);
	else if (key == KEY_S && game->map[game->param.y + 1][game->param.x] != '1')
		when_walk(&game->param.y, 1, &game->param.walk);
	else if (key == KEY_D && game->map[game->param.y][game->param.x + 1] != '1')
		when_walk(&game->param.x, 1, &game->param.walk);
	else if (key == KEY_A && game->map[game->param.y][game->param.x - 1] != '1')
		when_walk(&game->param.x, -1, &game->param.walk);
	else if (key == KEY_ESC)
	{
		printf("close");
		exit(0);
	}
	search_map(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_object(game);
	return (0);
}

int	exit_click(void)
{
	printf("close");
	exit(0);
}
