/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readElementsUtils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:46:18 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:41:19 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_color_utils(t_info *cub, int type, int hex)
{
	if (type == FLOOR && cub->ele.floor == -1)
		cub->ele.floor = hex;
	else if (type == CEILING && cub->ele.ceiling == -1)
		cub->ele.ceiling = hex;
	else
		ft_exit("ERROR: Multiple floor/ceiling colors");
}

int	valid_and_set_element_lines(t_info *cub, char **word, int cnt_word)
{
	int	type;

	valid_element_lines(word[0], cnt_word);
	type = set_elements(cub, word);
	return (type);
}
