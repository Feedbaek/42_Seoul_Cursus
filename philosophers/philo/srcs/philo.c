/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:20:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/04 21:28:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_status(t_philo *philo)
{
	if (philo->status == THINK)
		printf("%f %d is thinking\n", philo->age, philo->num);
	else if (philo->status == FORK)
		printf("%f %d has taken a fork\n", philo->age, philo->num);
	else if (philo->status == EAT)
		printf("%f %d is eating\n", philo->age, philo->num);
	else if (philo->status == SLEEP)
		printf("%f %d is sleeping\n", philo->age, philo->num);
	else if (philo->status == DIE)
		printf("%f %d died\n", philo->age, philo->num);
}

void	*running_pthread(void *p)
{
	t_philo			*philo;
	int				idx;
	struct timeval	start;
	struct timeval	end;

	philo = (t_philo *)p;
	idx = philo->num - 1;
	gettimeofday(&start, NULL);
	gettimeofday(&philo->time_to_die, NULL);
	while (philo->num_eat < philo->time_opt)
	{
		// 생각 시간
		philo->status = THINK;
		gettimeofday(&end, NULL);
		philo->age = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / (double)1000000);
		print_status(philo);
		// if 왼쪽 포크가 있으면,
		// pthread_muxtex_lock(왼쪽 포크);
		if(idx)
		{
			pthread_mutex_lock(&philo->mutex[idx]);
			philo->status = FORK;
			gettimeofday(&end, NULL);
			philo->age = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / (double)1000000);
			print_status(philo);
		// if 오른쪽 포크가 있으면,
		// pthread_muxtex_lock(오른쪽 포크);
			pthread_mutex_lock(&philo->mutex[(idx + 1) % philo->philo_num]);
		}
		else // 첫 철학자는 오른쪽 포크부터 확인함.
		{
			pthread_mutex_lock(&philo->mutex[(idx + 1) % philo->philo_num]);
			philo->status = FORK;
			gettimeofday(&end, NULL);
			philo->age = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / (double)1000000);
			print_status(philo);
			pthread_mutex_lock(&philo->mutex[idx]);
		}
		// 식사 타임
		philo->status = EAT;
		gettimeofday(&end, NULL);
		gettimeofday(&philo->time_to_die, NULL);
		philo->age = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / (double)1000000);
		print_status(philo);
		usleep(philo->num_eat);
		pthread_mutex_unlock(&philo->mutex[idx]);
		pthread_mutex_unlock(&philo->mutex[(idx + 1) % philo->philo_num]);
		philo->num_eat += 1;
		// pthread_mutex_unlock(왼쪽 포크);
		// pthread_mutex_unlock(오른쪽 포크);

		// 식사 끝나면자는 시간
		philo->status = SLEEP;
		gettimeofday(&end, NULL);
		philo->age = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / (double)1000000);
		print_status(philo);
		usleep(philo->time_sleep);
	}
	return (p);
}

void	mornitor_pthread(t_simul *simul)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < simul->philo_num)
		{
			if (simul->philo[i].time_to_die == )
		}
	}
}

void	wait_pthread(t_simul *simul)
{
	int	i;

	i = 0;
	while(i < simul->philo_num)
	{
		pthread_join(simul->thread[i], NULL);
		pthread_mutex_unlock(&simul->mutex[i]);
		pthread_mutex_destroy(&simul->mutex[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_simul	simul;

	if (!init_simul(&simul, argc, argv) || !init_pthread_mutex(&simul))
		return (-1);
	wait_pthread(&simul);
	// mutex_destroy 필요
	return (0);
}
