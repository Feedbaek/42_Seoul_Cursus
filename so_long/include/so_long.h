/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:19:25 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/22 15:03:29 by minskim2         ###   ########.fr       */
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
# define X_EVENT_KEY_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILE_SIZE 64

typedef struct s_param
{
	int	x;
	int	y;
	int	row;
	int	col;
	int	walk;
	int	num_collect;
	int	num_player;
	int	num_exit;
}	t_param;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	t_param	param;
}	t_game;

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*exit_so_long(char *error);

void	minilibx_init(t_game *game, char *file);
void	location_init(t_game *game);
void	map_init(t_game *game);

void	search_map(t_game *game);
void	set_map(t_game *game);
void	map_parse(t_game *game, char *file);

int		key_press(int key, t_game *game);
int		exit_click(void);

void	draw_object(t_game *game);
void	put_object(t_game *game, int row, int col, char *path);

#endif
