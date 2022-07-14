/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:21:32 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:30:29 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	load_image_from_xpm(t_info *cub, int *tex, char *xpm_path, t_img *img)
{
	int		x;
	int		y;

	img->ptr = mlx_xpm_file_to_image(cub->mlx, xpm_path,
			&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(
			img->ptr, &img->bpp, &img->size_line, &img->endian);
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			tex[img->width * y + x]
				= img->data[img->width * y + (img->width - x - 1)];
	}
	mlx_destroy_image(cub->mlx, img->ptr);
}

void	load_texture(t_info *cub)
{
	int		i;
	t_img	img;

	i = 0;
	while (i < 4)
	{
		load_image_from_xpm(cub, cub->ele.tex[i], cub->ele.xpm_path[i], &img);
		free(cub->ele.xpm_path[i]);
		i++;
	}
}

void	set_cub(t_info *cub)
{
	int	i;

	cub->buf = ft_calloc(cub->ele.render_y, sizeof(int **));
	if (!(cub->buf))
		ft_exit("ERROR: Fail to malloc buf(render_y)");
	i = -1;
	while (++i < cub->ele.render_y)
	{
		cub->buf[i] = ft_calloc(cub->ele.render_x, sizeof(int *));
		if (!(cub->buf[i]))
			ft_exit("ERROR: Fail to malloc buf(render_x)");
	}
	cub->z_buf = ft_calloc(cub->ele.render_x, sizeof(double *));
	if (!(cub->z_buf))
		ft_exit("ERROR: Fail to malloc z_buf");
	cub->mlx = mlx_init();
	load_texture(cub);
}
