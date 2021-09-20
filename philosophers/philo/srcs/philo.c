/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:20:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/21 01:34:29 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_philo(t_philo *philo, int argc, char **argv)
{
	philo->philo_num = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (philo->philo_num < 1 || philo->time_die < 1 || philo->time_eat < 1 || philo->time_sleep < 1)
		return (0);
	if (argc == 6)
	{
		philo->time_opt = ft_atoi(argv[5]);
		if (philo->time_opt < 1)
			return (0);
	}
	else
		philo->time_opt = 0;
	philo->philos = (pthread_t *)malloc(sizeof(pthread_t) * philo->philo_num);
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->philo_num);
	if (!philo->philos || !philo->forks)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (-1);
	if (!init_philo(&philo, argc, argv))
		return (-1);
	return (0);
}
