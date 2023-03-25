/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:15:56 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/13 21:09:09 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int way;
	int ret;

	way = 0;
	while (1 < length--)
	{
		ret = f(tab[length], tab[length - 1]);
		if (ret == 0)
			continue ;
		if (way == 0)
			way = ret;
		else	if ((way < 0 && ret > 0) || (way > 0 && ret < 0))
			return (0);
	}
	return (1);
}
