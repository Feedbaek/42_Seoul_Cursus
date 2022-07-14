/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingDDA.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:19:49 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:49:02 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_ray(t_info *cub, t_player *player, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)cub->width - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x * -1;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x * -1;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	calc_sidedist_step(t_player *player, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	applicate_dda(t_info *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = NORTH;
			else
				ray->side = SOUTH;
		}
		if (cub->map[ray->map_y][ray->map_x] == WALL)
			ray->hit = 1;
	}
}
