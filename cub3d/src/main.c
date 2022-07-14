/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:41:22 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:51:32 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_cub(t_info *cub, char *arg)
{
	ft_memset(cub, 0, sizeof(t_info));
	cub->ele.floor = -1;
	cub->ele.ceiling = -1;
	cub->ele.render_x = 1920;
	cub->ele.render_y = 1080;
	cub->width = cub->ele.render_x;
	cub->height = cub->ele.render_y;
	if (!ft_isformat(arg, ".cub"))
		ft_exit("ERROR: Invalid .cub file format");
	cub->fd = open(arg, O_RDONLY);
	if (cub->fd == -1)
		ft_exit("ERROR: Fail to open .cub file");
}

int	main(int argc, char **argv)
{
	t_info	cub;

	if (argc != 2)
	{
		printf("ERROR: Please write ./cub3D map.cub\n");
		return (0);
	}
	init_cub(&cub, argv[1]);
	read_cub_element_lines(&cub);
	read_cub_map_lines(&cub);
	valid_map(&cub);
	set_cub(&cub);
	start_game(&cub);
	return (0);
}
