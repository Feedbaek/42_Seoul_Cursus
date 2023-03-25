/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 05:14:52 by minskim2          #+#    #+#             */
/*   Updated: 2021/03/31 03:20:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	stamp(char *buf, int len, int x, int dep)
{
	int		i;

	if (dep == len)
	{
		write(1, buf, len);
		write(1, ", ", 2);
		return ;
	}
	i = x + 1;
	while (i <= 10 + dep - len)
	{
		buf[dep] = '0' + i;
		stamp(buf, len, i, dep + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		len;
	char	fin;
	char	buf[10];

	i = 0;
	len = n;
	while (i < 10 - n)
	{
		buf[0] = '0' + i;
		stamp(buf, len, i, 1);
		i++;
	}
	fin = buf[0] + 1;
	write(1, &fin, 1);
	write(1, &buf[1], len - 1);
}
