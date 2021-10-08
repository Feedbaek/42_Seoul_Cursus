/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:09 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/08 18:18:35 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_msg(t_philo *philo)
{
	if (philo->status == THINK)
		printf("%ld %d is thinking\n", philo->age, philo->num);
	else if (philo->status == FORK)
		printf("%ld %d has taken a fork\n", philo->age, philo->num);
	else if (philo->status == EAT)
		printf("%ld %d is eating\n", philo->age, philo->num);
	else if (philo->status == SLEEP)
		printf("%ld %d is sleeping\n", philo->age, philo->num);
}

void	*running_pthread(void *p)
{
	t_philo			*philo;
	int				idx;
	struct timeval	start;
	struct timeval	end;

	philo = (t_philo *)p;
	idx = philo->num - 1;
	philo->change = 1;
	while (1)
	{
		usleep(50);
		if (philo->start_point)
			break ;
	}
	gettimeofday(&start, NULL);
	usleep(50);
	while (1)
	{
		// 생각 시간
		philo->status = THINK;
		gettimeofday(&end, NULL);
		usleep(50);
		//philo->age = (end.tv_sec - start.tv_sec) * 1000 + ((end.tv_usec - start.tv_usec) / 1000);
		//print_status(philo);
		// if 왼쪽 포크가 있으면,
		// pthread_muxtex_lock(왼쪽 포크);
		if (idx)
		{
			pthread_mutex_lock(&philo->mutex[idx]);
			philo->status = FORK;
			philo->change = 1;
			gettimeofday(&end, NULL);
			usleep(50);
			//philo->age = (end.tv_sec - start.tv_sec) * 1000 + ((end.tv_usec - start.tv_usec) / 1000);
			//print_status(philo);
		// if 오른쪽 포크가 있으면,
		// pthread_muxtex_lock(오른쪽 포크);
			pthread_mutex_lock(&philo->mutex[(idx + 1) % philo->philo_num]);
		}
		else // 첫 철학자는 오른쪽 포크부터 확인함.
		{
			pthread_mutex_lock(&philo->mutex[(idx + 1) % philo->philo_num]);
			philo->status = FORK;
			philo->change = 1;
			gettimeofday(&end, NULL);
			usleep(50);
			//philo->age = (end.tv_sec - start.tv_sec) * 1000 + ((end.tv_usec - start.tv_usec) / 1000);
			//print_status(philo);
			pthread_mutex_lock(&philo->mutex[idx]);
		}
		// 식사 타임
		usleep(50);
		philo->status = EAT;
		philo->change = 1;
		gettimeofday(&end, NULL);
		//philo->age = (end.tv_sec - start.tv_sec) * 1000 + ((end.tv_usec - start.tv_usec) / 1000);
		//print_status(philo);
		usleep(philo->time_eat * 1000);
		pthread_mutex_unlock(&philo->mutex[idx]);
		pthread_mutex_unlock(&philo->mutex[(idx + 1) % philo->philo_num]);
		philo->num_eat += 1;
		if (philo->time_opt && philo->num_eat >= philo->time_opt)
			philo->end_eat = 1;
		if (philo->end_game)
			return (p);
		// pthread_mutex_unlock(왼쪽 포크);
		// pthread_mutex_unlock(오른쪽 포크);

		// 식사 끝나면자는 시간
		philo->status = SLEEP;
		philo->change = 1;
		gettimeofday(&end, NULL);
		//philo->age = (end.tv_sec - start.tv_sec) * 1000 + ((end.tv_usec - start.tv_usec) / 1000);
		//print_status(philo);
		usleep(philo->time_sleep * 1000);
		philo->change = 1;
	}
	return (p);
}

void	*mornitor_pthread(void *s)
{
	int				i;
	int				check_end;
	t_simul			*simul;
	struct timeval	start_time;
	struct timeval	current_time;

	simul = (t_simul *)s;
	simul->start_point = 1;
	gettimeofday(&start_time, NULL);
	i = 0;
	while (i < simul->philo_num)
	{
		gettimeofday(&simul->philo[i].last_eat, NULL);
		i++;
	}
	while (1)
	{
		if (simul->end)
			return (s);
		check_end = 1;
		i = 0;
		while (i < simul->philo_num)
		{
			// 죽었는지 검사, 아무도 안죽었으면 상태 변화 감지 단계로 넘어감.
			gettimeofday(&current_time, NULL);
			simul->philo[i].age = (current_time.tv_sec - start_time.tv_sec) * 1000 + ((current_time.tv_usec - start_time.tv_usec) / 1000);
			//printf("check_die: %ld ", simul->philo[i].age);
			if ((current_time.tv_sec - simul->philo[i].last_eat.tv_sec) * 1000 + ((current_time.tv_usec - simul->philo[i].last_eat.tv_usec) / 1000) >= simul->time_die)
			{
				printf("%ld %d died\n", simul->philo[i].age, simul->philo[i].num);
				i = 0;
				while(i < simul->philo_num)
				{
					pthread_detach(simul->thread[i]);
					pthread_mutex_unlock(&simul->mutex[i]);
					pthread_mutex_destroy(&simul->mutex[i]);
					//simul->philo[i].end_game = 1;
					i++;
				}
				return (s);
			}
			if (!simul->philo[i].end_eat)
				check_end = 0;
			i++;
		}
		if (check_end)
		{
			printf("all eat\n");
			i = 0;
			while(i < simul->philo_num)
			{
				pthread_detach(simul->thread[i]);
				pthread_mutex_unlock(&simul->mutex[i]);
				pthread_mutex_destroy(&simul->mutex[i]);
				//simul->philo[i].end_game = 1;
				i++;
			}
			return (s);
		}
		i = 0;
		while (i < simul->philo_num) // 죽은 철학자가 없으니 변화가 있는지 검사
		{
			gettimeofday(&current_time, NULL);
			simul->philo[i].age = (current_time.tv_sec - start_time.tv_sec) * 1000 + ((current_time.tv_usec - start_time.tv_usec) / 1000);
			//printf("check_change: %ld ", simul->philo[i].age);
			if (simul->philo[i].change)
			{
				if (simul->philo[i].status == SLEEP)
				{
					gettimeofday(&simul->philo[i].last_eat, NULL);
				}
				print_msg(&simul->philo[i]);
				simul->philo[i].change = 0;
			}
			i++;
		}
	}
	return (s);
}

int	wait_pthread(t_simul *simul)
{
	//int	i;
	int	status;
	//int	*ret;

	//i = 0;
	status = pthread_create(&simul->thread[simul->philo_num], NULL, mornitor_pthread, (void *)simul);
	if (status < 0)
		return (0);
	//while(i < simul->philo_num)
	//{
	//	pthread_join(simul->thread[i], NULL);
	//	pthread_mutex_unlock(&simul->mutex[i]);
	//	pthread_mutex_destroy(&simul->mutex[i]);
	//	i++;
	//}
	//simul->end = 1;
	pthread_join(simul->thread[simul->philo_num], NULL);
		return (1);
	//if (ret == 0)
	//	return (0);
	return (0);
}

