/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:09:07 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/12 00:33:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	diff;

	if (min >= max)
		return (0);
	diff = max - min;
	*range = (int *)malloc(sizeof(int) * diff);
	if (!*range)
		return (-1);
	arr = *range;
	while (min < max)
		*(arr++) = min++;
	return (diff);
}
