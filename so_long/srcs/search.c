/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:01:55 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/21 19:48:21 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	get_collect(t_game *game)
{
	if (game->map[game->param.y][game->param.x] == 'C')
	{
		game->map[game->param.y][game->param.x] = '0';
		game->param.num_collect--;
	}
}

static	void	reach_exit(t_game *game)
{
	if (game->map[game->param.y][game->param.x] == 'E'
		&& game->param.num_collect == 0)
	{
		printf("wow, clear!!! your step is: %d\n", game->param.walk);
		exit(0);
	}
}

void	search_map(t_game *game)
{
	get_collect(game);
	reach_exit(game);
}
