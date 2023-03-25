/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:01:42 by minskim2          #+#    #+#             */
/*   Updated: 2021/03/29 20:29:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int n)
{
	int tmp;

	tmp = tab[n];
	tab[n] = tab[n + 1];
	tab[n + 1] = tmp;
}

void	sort(int *tab, int size, int i)
{
	int start;

	start = 0;
	while (start < size - i - 1)
	{
		if (tab[start] > tab[start + 1])
			swap(tab, start);
		start++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		sort(tab, size, i);
		i++;
	}
}
