/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:20:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/21 21:42:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_philo(t_simul *simul, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	simul->philo_num = ft_atoi(argv[1]);
	simul->time_die = ft_atoi(argv[2]);
	simul->time_eat = ft_atoi(argv[3]);
	simul->time_sleep = ft_atoi(argv[4]);
	if (simul->philo_num < 1 || simul->time_die < 1 || simul->time_eat < 1 || simul->time_sleep < 1)
		return (0);
	if (argc == 6)
	{
		simul->time_opt = ft_atoi(argv[5]);
		if (simul->time_opt < 1)
			return (0);
	}
	else
		simul->time_opt = 0;
	simul->thread = (pthread_t *)malloc(sizeof(pthread_t) * simul->philo_num);
	simul->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * simul->philo_num);
	if (!simul->thread || !simul->mutex)
		return (0);
	return (1);
}

void	*philo_survive(void *p)
{
	printf("%d ", ((t_simul *)p)->philo_num--);
	return (p);
}

int	make_pthread(t_simul *simul)
{
	int	i;
	int	status;

	i = 0;
	while (i < 10)
	{
		status = pthread_create(&simul->thread[i], NULL, philo_survive, (void *)simul);
		usleep(50);
		if (status < 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_simul	simul;

	if (!init_philo(&simul, argc, argv))
		return (-1);
	make_pthread(&simul);
	return (0);
}
