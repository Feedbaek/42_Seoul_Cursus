/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:49:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/30 02:24:57 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_press(int key, t_param *param)
{
	if (key == KEY_W)
		param->x++;
	else if (key == KEY_S)
		param->x--;
	else if (key == KEY_D)
		param->y++;
	else if (key == KEY_A)
		param->y--;
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}
