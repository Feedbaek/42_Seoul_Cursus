/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:29:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/15 13:46:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERROR_QUIT "Stop : division by zero\n"
#define ERROR_RMID "Stop : modulo by zero\n"
#include "do.h"

int			(*g_f[5])(int, int);

void		ft_init(void)
{
	g_f[0] = sum;
	g_f[1] = sub;
	g_f[2] = mul;
	g_f[3] = div;
	g_f[4] = mod;
}

int			ch_oper(char c)
{
	ft_init();
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == '*')
		return (2);
	if (c == '/')
		return (3);
	if (c == '%')
		return (4);
	write(1, "0\n", 2);
	return (-1);
}

int			main(int n, char *str[])
{
	int op;

	if (n - 1 != 3)
		return (0);
	op = ch_oper(*str[2]);
	if (op == -1)
		return (0);
	if (*str[3] == '0')
	{
		if (*str[2] == '/')
		{
			write(1, ERROR_QUIT, 24);
			return (0);
		}
		if (*str[2] == '%')
		{
			write(1, ERROR_RMID, 22);
			return (0);
		}
	}
	ft_putnbr(g_f[op](ft_atoi(str[1]), ft_atoi(str[3])));
	return (0);
}
