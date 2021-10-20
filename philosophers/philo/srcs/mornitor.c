/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mornitor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:40:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/20 21:12:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_die(t_simul *simul)
{
	int	i;
	int	check_end;
	struct timeval	current_time;

	check_end = 1;
	i = 0;
	while (i < simul->philo_num)
	{
		gettimeofday(&current_time, NULL);
		usleep(1000);
		if ((current_time.tv_sec - simul->philo[i].last_eat.tv_sec) * 1000 \
		+ ((current_time.tv_usec - simul->philo[i].last_eat.tv_usec) \
		/ 1000) > simul->time_die)
		{
			print_msg(&simul->philo[i], DIE);
			i = 0;
			while (i < simul->philo_num)
				simul->philo[i++].status = DIE;
			return (1);
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
	simul->start_point = 1;
	while (i < simul->philo_num)
	{
		simul->philo[i].start_time = start_time;
		simul->philo[i].last_eat = start_time;
		i++;
	}
	while (1)
	{
		if (check_die(simul))
			return (s);
	}
	return (s);
}
