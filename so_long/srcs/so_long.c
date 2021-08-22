/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:42:34 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/22 15:00:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		exit_so_long("argc");
	minilibx_init(&game, argv[1]);
	map_init(&game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, &exit_click, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
