/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:52:21 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/14 17:45:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (*str == '\t' || *str == ' '
		|| *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	if (*str)
		return (0);
	return (sign * i);
}

void	print_msg(t_philo *philo)
{
	if (philo->status == THINK)
		printf("%ld %d is thinking\n", philo->age, philo->num);
	else if (philo->status == FORK)
		printf("%ld %d has taken a fork\n", philo->age, philo->num);
	else if (philo->status == EAT)
		printf("%ld %d is eating\n", philo->age, philo->num);
	else if (philo->status == SLEEP)
		printf("%ld %d is sleeping\n", philo->age, philo->num);
}
