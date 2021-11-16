/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:09 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/31 17:17:04 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	check_ready(t_philo *philo)
{
	int	i;
	int	flag;

	while (1)
	{
		i = 0;
		flag = 1;
		while (i < philo->philo_num)
		{
			if (!philo->philo[i].ready)
				flag = 0;
			i++;
		}
		if (flag)
		{
			*philo->last_start_point = 1;
			return ;
		}
	}
}

static t_philo	*running_start(void *p, int *idx)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	*idx = philo->num - 1;
	philo->status = THINK;
	philo->ready = 1;
	check_ready(philo);
	while (1)
	{
		usleep(50);
		if (*philo->start_point)
			break ;
	}
	return (philo);
}

static void	usleep_to_eat(t_philo *philo, int idx)
{
	if (idx == philo->philo_num - 1)
	{
		if (philo->num_start_eat >= \
		philo->philo[(idx + 1) % philo->philo_num].num_start_eat)
			usleep(philo->time_eat * 1000);
	}
	else if (philo->num_start_eat > \
	philo->philo[(idx + 1) % philo->philo_num].num_start_eat)
		usleep(philo->time_eat * 500);
	pthread_mutex_lock(&philo->mutex[(idx + 1) % philo->philo_num]);
	print_msg(philo, FORK);
	if (philo->num_start_eat > philo->philo[(idx - 1 + philo->philo_num) \
	% philo->philo_num].num_start_eat)
		usleep(philo->time_eat * 500);
	pthread_mutex_lock(&philo->mutex[idx]);
	print_msg(philo, FORK);
}

static void	running_think(t_philo *philo, int idx)
{
	print_msg(philo, THINK);
	if (idx % 2 == 0)
		usleep_to_eat(philo, idx);
	else
	{
		if (philo->num_start_eat == 0)
			usleep(philo->time_eat * 300);
		if (philo->num_start_eat >= philo->philo[(idx - 1 + philo->philo_num) \
		% philo->philo_num].num_start_eat)
			usleep(philo->time_eat * 500);
		pthread_mutex_lock(&philo->mutex[idx]);
		print_msg(philo, FORK);
		if (philo->num_start_eat >= \
		philo->philo[(idx + 1) % philo->philo_num].num_start_eat)
			usleep(philo->time_eat * 500);
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
		if (*philo->end_game)
			return (p);
		running_think(philo, idx);
		philo->num_start_eat += 1;
		print_msg(philo, EAT);
		usleep(philo->time_eat * 1000);
		gettimeofday(&philo->last_eat, NULL);
		pthread_mutex_unlock(&philo->mutex[idx]);
		pthread_mutex_unlock(&philo->mutex[(idx + 1) % philo->philo_num]);
		philo->num_eat = philo->num_start_eat;
		if (philo->time_opt && philo->num_eat >= philo->time_opt)
			philo->end_eat = 1;
		print_msg(philo, SLEEP);
		usleep(philo->time_sleep * 1000);
	}
	return (p);
}
