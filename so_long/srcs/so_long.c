/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:42:34 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/31 22:18:45 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	//void	*img_ptr;
	t_param	param;
	//int		width;
	//int		height;

	mlx_ptr = mlx_init();
	param_init(&param);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	//img_ptr = mlx_xpm_file_to_image(mlx_ptr, "../img/test.xpm", &width, &height);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx_ptr);
	return (0);
}
