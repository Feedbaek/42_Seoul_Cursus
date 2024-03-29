/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:51:44 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/31 14:11:33 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	init_philo(t_simul *simul)
{
	int	i;

	i = 0;
	while (i < simul->philo_num)
	{
		simul->philo[i].philo_num = simul->philo_num;
		simul->philo[i].num = i + 1;
		simul->philo[i].dead_time = 0;
		simul->philo[i].status = THINK;
		simul->philo[i].time_eat = simul->time_eat;
		simul->philo[i].time_sleep = simul->time_sleep;
		simul->philo[i].time_opt = simul->time_opt;
		simul->philo[i].num_start_eat = 0;
		simul->philo[i].num_eat = 0;
		simul->philo[i].end_eat = 0;
		simul->philo[i].ready = 0;
		simul->philo[i].end_game = &simul->end_game;
		simul->philo[i].mutex = simul->mutex;
		simul->philo[i].start_point = &simul->start_point;
		simul->philo[i].last_start_point = &simul->last_start_point;
		simul->philo[i].philo = simul->philo;
		simul->philo[i].current_time = &simul->current_time;
		i++;
	}
}

static int	start_init(int argc, char **argv, t_simul *simul)
{
	if (argc < 5 || argc > 6)
		return (0);
	simul->philo_num = ft_atoi(argv[1]);
	simul->time_die = ft_atoi(argv[2]);
	simul->time_eat = ft_atoi(argv[3]);
	simul->time_sleep = ft_atoi(argv[4]);
	simul->start_point = 0;
	simul->last_start_point = 0;
	simul->end_game = 0;
	if (!simul->philo_num || !simul->time_die
		|| !simul->time_eat || !simul->time_sleep)
		return (0);
	return (1);
}

int	init_simul(t_simul *simul, int argc, char **argv)
{
	if (!start_init(argc, argv, simul))
		return (0);
	if (simul->philo_num < 1 || simul->time_die < 1
		|| simul->time_eat < 1 || simul->time_sleep < 1)
		return (0);
	if (argc == 6)
	{
		simul->time_opt = ft_atoi(argv[5]);
		if (simul->time_opt < 1)
			return (0);
	}
	else
		simul->time_opt = 0;
	simul->thread = (pthread_t *)malloc(sizeof(pthread_t) \
		* (simul->philo_num + 1));
	simul->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* simul->philo_num);
	simul->philo = (t_philo *)malloc(sizeof(t_philo) * simul->philo_num);
	if (!simul->thread || !simul->mutex || !simul->philo)
		return (0);
	init_philo(simul);
	return (1);
}

int	init_pthread_mutex(t_simul *simul)
{
	int	i;
	int	status;

	i = 0;
	while (i < simul->philo_num)
	{
		status = pthread_create(&simul->thread[i], NULL, \
			running_pthread, (void *)&simul->philo[i]);
		if (status != 0 || pthread_mutex_init(&simul->mutex[i], NULL))
			return (0);
		i++;
	}
	return (1);
}
