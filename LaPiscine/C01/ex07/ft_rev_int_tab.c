/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:29:23 by minskim2          #+#    #+#             */
/*   Updated: 2021/03/29 20:00:40 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int left;
	int right;
	int tmp;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		tmp = tab[left];
		tab[left] = tab[right];
		tab[right] = tmp;
		right--;
		left++;
	}
}
