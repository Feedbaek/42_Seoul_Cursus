/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:09 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/22 01:26:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static t_philo	*running_start(void *p, int *idx)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	*idx = philo->num - 1;
	philo->status = THINK;
	if (philo->num == philo->philo_num)
		*philo->last_start_point = 1;
	while (1)
	{
		usleep(50);
		if (*philo->start_point)
			break ;
	}
	return (philo);
}

static void	running_think(t_philo *philo, int idx)
{
	usleep(200);
	print_msg(philo, THINK);
	//if (philo->num_eat == 0)
	if (idx % 2 == 0)
	{
		pthread_mutex_lock(&philo->mutex[(idx + 1) % philo->philo_num]);
		print_msg(philo, FORK);
		pthread_mutex_lock(&philo->mutex[idx]);
		print_msg(philo, FORK);
	}
	else
	{
		if (philo->num_eat == 0)
			usleep(philo->time_eat * 1000);
		pthread_mutex_lock(&philo->mutex[idx]);
		print_msg(philo, FORK);
		pthread_mutex_lock(&philo->mutex[(idx + 1) % philo->philo_num]);
		print_msg(philo, FORK);
	}
}

void	*running_pthread(void *p)
{
	t_philo			*philo;
	int				idx;

	philo = running_start(p, &idx);
	while (1)
	{
		running_think(philo, idx);
		print_msg(philo, EAT);
		usleep(philo->time_eat * 1000);
		gettimeofday(&philo->last_eat, NULL);
		pthread_mutex_unlock(&philo->mutex[idx]);
		pthread_mutex_unlock(&philo->mutex[(idx + 1) % philo->philo_num]);
		philo->num_eat += 1;
		if (philo->time_opt && philo->num_eat >= philo->time_opt)
			philo->end_eat = 1;
		print_msg(philo, SLEEP);
		usleep(philo->time_sleep * 1000);
	}
	return (p);
}

int	end_mutex(t_simul *simul)
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

int	wait_pthread(t_simul *simul)
{
	int	status;

	usleep(10000);
	status = pthread_create(&simul->thread[simul->philo_num], \
	NULL, mornitor_pthread, (void *)simul);
	if (status < 0)
		return (0);
	pthread_join(simul->thread[simul->philo_num], NULL);
	//end_mutex(simul);
	return (1);
}
