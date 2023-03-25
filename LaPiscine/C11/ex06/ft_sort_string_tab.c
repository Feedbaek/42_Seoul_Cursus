/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:20:55 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/13 21:44:37 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (*a - *b);
}

int		size_tab(char **tab)
{
	int size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[idx - 1], tab[idx]) > 0)
			{
				tmp = tab[idx - 1];
				tab[idx - 1] = tab[idx];
				tab[idx] = tmp;
			}
		}
	}
}
