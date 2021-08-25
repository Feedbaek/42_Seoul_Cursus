/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:48:37 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 16:00:14 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i = (i * 10) + sign * (*str - '0');
		if ((sign < 0 && i > 0) || (sign > 0 && i < 0))
			error_push_swap("Error\n");
		str++;
	}
	if (*str != 0)
		error_push_swap("Error\n");
	return (i);
}
