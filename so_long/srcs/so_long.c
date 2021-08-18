/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:42:34 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/18 13:34:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(void)
{
	t_mlx	mlx;
	t_img	img;
	t_param	param;
	//int		width;
	//int		height;
	int		count_w;
	int		count_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 600, "mlx 42");
	param_init(&param);
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, 400, 300);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	//img.img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "./img/test.xpm", &width, &height);
	count_h = -1;
	while (++count_h < 300)
	{
		count_w = -1;
		while (++count_w < 400)
		{
			if (count_w % 2)
				img.data[count_h * 400 + count_w] = 0xFFFFFF;
			else
				img.data[count_h * 400 + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
