/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:44:10 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/06 11:10:53 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int negative;

	i = 0;
	negative = 1;
	while (*str == '\t'
			|| *str == ' '
			|| *str == '\n'
			|| *str == '\f'
			|| *str == '\v'
			|| *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i *= 10;
		i += (negative * (*str - '0'));
		str++;
	}
	return (i);
}
