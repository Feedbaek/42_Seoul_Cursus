/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:19:25 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/19 00:20:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <get_next_line.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILE_SIZE 60
# define COL 5
# define ROW 5
# define WIDTH TILE_SIZE * COL
# define HEIGHT TILE_SIZE * ROW

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		map[ROW][COL];
}	t_game;

void	param_init(t_param *param);
int		key_press(int key, t_param *param);

#endif
