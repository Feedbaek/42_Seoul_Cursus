/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mornitor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:40:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/15 21:16:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_die(t_simul *simul, struct timeval *start_time, \
	struct timeval *current_time)
{
	int	i;
	int	check_end;

	check_end = 1;
	i = 0;
	while (i < simul->philo_num)
	{
		gettimeofday(current_time, NULL);
		simul->philo[i].age = (current_time->tv_sec - start_time->tv_sec) \
		* 1000 + ((current_time->tv_usec - start_time->tv_usec) / 1000);
		if (simul->philo[i].change)
		{
			simul->philo[i].change = 0;
			if (simul->philo[i].status == SLEEP)
				gettimeofday(&simul->philo[i].last_eat, NULL);
			print_msg(&simul->philo[i]);
		}
		if ((current_time->tv_sec - simul->philo[i].last_eat.tv_sec) * 1000 \
		+ ((current_time->tv_usec - simul->philo[i].last_eat.tv_usec) \
		/ 1000) > simul->time_die + 10)
		{
			printf("%ld %d died\n", simul->philo[i].age, \
			simul->philo[i].num);
			print_msg(&simul->philo[i]);
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

//static void	check_status(t_simul *simul, struct timeval *start_time, \
//	struct timeval *current_time)
//{
//	int	i;

//	i = 0;
//	while (i < simul->philo_num)
//	{
//		gettimeofday(current_time, NULL);
//		simul->philo[i].age = (current_time->tv_sec - start_time->tv_sec) \
//		* 1000 + ((current_time->tv_usec - start_time->tv_usec) / 1000);
//		if (simul->philo[i].change)
//		{
//			simul->philo[i].change = 0;
//			if (simul->philo[i].status == SLEEP)
//				gettimeofday(&simul->philo[i].last_eat, NULL);
//			print_msg(&simul->philo[i]);
//		}
//		i++;
//	}
//}

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
		//check_status(simul, &start_time, &current_time);
	}
	return (s);
}
