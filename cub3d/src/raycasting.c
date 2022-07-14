/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:18:41 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:49:14 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_background(t_info *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->height)
	{
		x = -1;
		while (++x < cub->width)
		{
			if (y > cub->height / 2)
				cub->buf[y][x] = cub->ele.floor;
			else
				cub->buf[y][x] = cub->ele.ceiling;
		}
	}
}

void	raycast_wall(t_info *cub)
{
	int	x;

	x = -1;
	while (++x < cub->width)
	{
		init_ray(cub, &cub->player, &cub->ray, x);
		calc_sidedist_step(&cub->player, &cub->ray);
		applicate_dda(cub, &cub->ray);
		calc_distance_wall(&cub->player, &cub->ray);
		calc_height_wall(cub, &cub->ray);
		set_tex_x_wall(&cub->player, &cub->ray);
		set_tex_y_wall(cub, &cub->ray, x);
		cub->z_buf[x] = cub->ray.perp_wall_dist;
	}
}

void	render(t_info *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->height)
	{
		x = -1;
		while (++x < cub->width)
			cub->img.data[cub->width * y + x] = cub->buf[y][x];
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.ptr, 0, 0);
}

int	raycast(t_info *cub)
{
	set_background(cub);
	raycast_wall(cub);
	render(cub);
	return (0);
}
