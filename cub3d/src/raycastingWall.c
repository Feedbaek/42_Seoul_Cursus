/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingWall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:20:03 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:44:25 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	calc_distance_wall(t_player *player, t_ray *ray)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->perp_wall_dist = (ray->map_x - player->pos_x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	else if (ray->side == NORTH || ray->side == SOUTH)
		ray->perp_wall_dist = (ray->map_y - player->pos_y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
}

void	calc_height_wall(t_info *cub, t_ray *ray)
{
	ray->line_height = (int)(cub->height / ray->perp_wall_dist);
	ray->draw_start_y = -ray->line_height / 2 + cub->height / 2;
	if (ray->draw_start_y < 0)
		ray->draw_start_y = 0;
	ray->draw_end_y = ray->line_height / 2 + cub->height / 2;
	if (ray->draw_end_y >= cub->height)
		ray->draw_end_y = cub->height - 1;
}

void	set_tex_x_wall(t_player *player, t_ray *ray)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else if (ray->side == NORTH || ray->side == SOUTH)
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == EAST || ray->side == SOUTH)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
}

void	set_tex_y_wall(t_info *cub, t_ray *ray, int x)
{
	int	color;
	int	y;

	ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start_y - cub->height / 2
			+ ray->line_height / 2) * ray->step;
	y = ray->draw_start_y;
	while (y < ray->draw_end_y)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		color = cub->ele.tex[ray->side][TEX_HEIGHT * ray->tex_y + ray->tex_x];
		cub->buf[y][x] = color;
		y++;
	}
}
