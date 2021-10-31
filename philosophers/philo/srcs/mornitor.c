/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mornitor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:40:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/31 16:51:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	loop_check(t_simul *simul, int i, int *check_end)
{
	if (get_time_diff(simul->current_time, \
		simul->philo[i].last_eat) > simul->time_die)
	{
		simul->philo[i].dead_time = get_time_diff(simul->current_time, \
			simul->philo[i].start_time);
		usleep(5000);
		if (get_time_diff(simul->current_time, \
			simul->philo[i].last_eat) > simul->time_die)
		{
			usleep(simul->philo_num * 30);
			if (get_time_diff(simul->current_time, \
				simul->philo[i].last_eat) > simul->time_die)
			{
				*(simul->philo[i].end_game) = 1;
				usleep(200);
				print_msg(&simul->philo[i], DIE);
				return (1);
			}
		}
	}
	if (!simul->philo[i].end_eat)
		*check_end = 0;
	return (0);
}

static int	check_die(t_simul *simul)
{
	int				i;
	int				check_end;

	check_end = 1;
	i = 0;
	gettimeofday(&simul->current_time, NULL);
	while (i < simul->philo_num)
	{
		if (loop_check(simul, i, &check_end))
			return (1);
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
		if (check_die(simul))
			return (s);
	return (s);
}

static int	end_mutex(t_simul *simul)
{
	int	i;

	i = 0;
	while (i < simul->philo_num)
	{
		pthread_detach(simul->thread[i]);
		i++;
	}
	i = 0;
	while (i < simul->philo_num)
	{
		pthread_mutex_unlock(&simul->mutex[i]);
		pthread_mutex_destroy(&simul->mutex[i]);
		i++;
	}
	return (1);
}

int	wait_mornitor(t_simul *simul)
{
	int	status;

	usleep(10000);
	status = pthread_create(&simul->thread[simul->philo_num], \
	NULL, mornitor_pthread, (void *)simul);
	if (status != 0)
		return (0);
	pthread_join(simul->thread[simul->philo_num], NULL);
	end_mutex(simul);
	usleep(10000);
	return (1);
}
