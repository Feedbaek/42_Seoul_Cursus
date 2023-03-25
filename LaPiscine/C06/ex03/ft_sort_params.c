/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:30:17 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/06 23:38:35 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *c1, char *c2)
{
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (*c1 - *c2);
}

void	print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	sort(int n, char *str[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < n)
	{
		j = 2;
		while (j < n)
		{
			if (ft_strcmp(str[j - 1], str[j]) < 0)
			{
				tmp = str[j - 1];
				str[j - 1] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		main(int n, char *str[])
{
	sort(n, str);
	while (--n)
		print(str[n]);
	return (0);
}
