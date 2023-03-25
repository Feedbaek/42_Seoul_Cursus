/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:43:18 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/12 00:29:41 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*arr;
	int	*tmp;

	if (min >= max)
		return (0);
	arr = malloc(sizeof(int) * ((long long)max - min));
	if (!arr)
		return (0);
	tmp = arr;
	while (min < max)
		*(tmp++) = min++;
	return (arr);
}
