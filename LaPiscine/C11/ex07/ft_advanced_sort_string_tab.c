/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:16:20 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/13 21:45:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_tab(char **tab)
{
	int size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char*))
{
	int		i;
	int		idx;
	int		size;
	char	*tmp;

	size = size_tab(tab);
	i = 1;
	while (i++ < size)
	{
		idx = 0;
		while (++idx < size)
		{
			if (cmp(tab[idx - 1], tab[idx]) > 0)
			{
				tmp = tab[idx - 1];
				tab[idx - 1] = tab[idx];
				tab[idx] = tmp;
			}
		}
	}
}
