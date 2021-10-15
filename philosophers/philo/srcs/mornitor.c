/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mornitor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:40:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/16 02:52:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	check_status(t_philo *philo, struct timeval *start_time, \
	struct timeval *current_time)
{
	gettimeofday(current_time, NULL);
	philo->age = (current_time->tv_sec - start_time->tv_sec) \
		* 1000 + ((current_time->tv_usec - start_time->tv_usec) / 1000);
	if (philo->change)
	{
		philo->change = 0;
		if (philo->status == SLEEP)
			gettimeofday(&philo->last_eat, NULL);
		print_msg(philo);
	}
}

static int	check_die(t_simul *simul, struct timeval *start_time, \
	struct timeval *current_time)
{
	int	i;
	int	check_end;

	check_end = 1;
	i = 0;
	while (i < simul->philo_num)
	{
		check_status(&simul->philo[i], start_time, current_time);
		if ((current_time->tv_sec - simul->philo[i].last_eat.tv_sec) * 1000 \
		+ ((current_time->tv_usec - simul->philo[i].last_eat.tv_usec) \
		/ 1000) > simul->time_die)
		{
			printf("%ld %d died\n", simul->philo[i].age, \
			simul->philo[i].num);
			return (end_mutex(simul));
		}
		if (!simul->philo[i].end_eat)
			check_end = 0;
		i++;
	}
	if (check_end)
		return (end_mutex(simul));
	return (0);
}

void	*mornitor_pthread(void *s)
{
	int				i;
	t_simul			*simul;
	struct timeval	start_time;
	struct timeval	current_time;

	simul = (t_simul *)s;
	simul->start_point = 1;
	gettimeofday(&start_time, NULL);
	i = 0;
	while (i < simul->philo_num)
		gettimeofday(&simul->philo[i++].last_eat, NULL);
	while (1)
	{
		if (check_die(simul, &start_time, &current_time))
			return (s);
	}
	return (s);
}
