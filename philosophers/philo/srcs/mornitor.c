/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mornitor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:40:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/22 02:11:37 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_die(t_simul *simul)
{
	int				i;
	int				check_end;
	struct timeval	current_time;

	check_end = 1;
	i = 0;
	while (i < simul->philo_num)
	{
		gettimeofday(&current_time, NULL);
		if ((current_time.tv_sec - simul->philo[i].last_eat.tv_sec) * 1000 \
		+ ((current_time.tv_usec - simul->philo[i].last_eat.tv_usec) \
		/ 1000) > simul->time_die)
		{
			simul->philo[i].dead_time = (current_time.tv_sec - simul->philo[i].start_time.tv_sec) \
				* 1000 + ((current_time.tv_usec - simul->philo[i].start_time.tv_usec) / 1000);
			//pthread_mutex_lock(&simul->print_lock);
			usleep(simul->philo_num * 50);
			if ((current_time.tv_sec - simul->philo[i].last_eat.tv_sec) * 1000 \
				+ ((current_time.tv_usec - simul->philo[i].last_eat.tv_usec) \
				/ 1000) > simul->time_die)
			{
				usleep(simul->philo_num * 50);
				if ((current_time.tv_sec - simul->philo[i].last_eat.tv_sec) * 1000 \
					+ ((current_time.tv_usec - simul->philo[i].last_eat.tv_usec) \
					/ 1000) > simul->time_die)
				{
					end_mutex(simul);
					*(simul->philo[i].end_game) = 1;
					print_msg(&simul->philo[i], DIE);
					return (1);
				}
			}
			//pthread_mutex_unlock(&simul->print_lock);
		}
		if (!simul->philo[i].end_eat)
			check_end = 0;
		i++;
	}
	if (check_end)
		return (1);
	return (0);
}

void	*mornitor_pthread(void *s)
{
	int				i;
	t_simul			*simul;
	struct timeval	start_time;

	simul = (t_simul *)s;
	while (1)
	{
		usleep(50);
		if (simul->last_start_point)
			break ;
	}
	gettimeofday(&start_time, NULL);
	i = 0;
	while (i < simul->philo_num)
	{
		simul->philo[i].start_time = start_time;
		simul->philo[i].last_eat = start_time;
		i++;
	}
	simul->start_point = 1;
	while (1)
	{
		usleep(200);
		if (check_die(simul))
			return (s);
	}
	return (s);
}
