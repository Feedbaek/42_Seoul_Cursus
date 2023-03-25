/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:24:12 by minskim2          #+#    #+#             */
/*   Updated: 2021/03/28 23:06:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *buf, int x)
{
	write(1, buf, 7);
	if (buf[x + 1] == '9')
	{
		buf[x]++;
		buf[x + 1] = '0';
	}
	else
	{
		buf[x + 1]++;
	}
}

void	check(char *buf)
{
	if (buf[1] == '9')
	{
		++buf[3];
		buf[4] = '0';
	}
	else
	{
		buf[4] = buf[1] + 1;
	}
}

void	ft_print_comb2(void)
{
	char buf[7];

	buf[0] = '0';
	buf[1] = '0';
	buf[2] = ' ';
	buf[5] = ',';
	buf[6] = ' ';
	while (buf[0] != '9' || buf[1] != '8')
	{
		buf[3] = buf[0];
		check(buf);
		while (buf[3] != '9' || buf[4] != '9')
		{
			print(buf, 3);
		}
		print(buf, 0);
	}
	write(1, "98 99", 5);
}
