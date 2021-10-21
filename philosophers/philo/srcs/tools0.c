/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:52:21 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/21 21:09:56 by minskim2         ###   ########.fr       */
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

void	print_msg(t_philo *philo, int status)
{
	struct timeval	current_time;
	size_t			time;

	if (status != DIE && *philo->end_game)
		return ;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec - philo->start_time.tv_sec) \
		* 1000 + ((current_time.tv_usec - philo->start_time.tv_usec) / 1000);
	if (status == DIE)
	{
		usleep(10000);
		printf("%ld %d is died: eat:%d\n", philo->dead_time, philo->num, philo->num_eat);
	}
	else if (status == THINK)
		printf("%ld %d is thinking: eat:%d\n", time, philo->num, philo->num_eat);
	else if (status == FORK)
		printf("%ld %d has taken a fork: eat:%d\n", time, philo->num, philo->num_eat);
	else if (status == EAT)
		printf("%ld %d is eating: eat:%d\n", time, philo->num, philo->num_eat);
	else if (status == SLEEP)
		printf("%ld %d is sleeping: eat:%d\n", time, philo->num, philo->num_eat);
	philo->change = 0;
}

int		get_time_diff(struct timeval current_time, struct timeval start_time)
{
	return ((current_time.tv_sec - start_time.tv_sec) * 1000 + ((current_time.tv_usec - start_time.tv_usec) / 1000));
}
