/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:20:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/22 20:05:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_survive(void *p)
{
	while (1)
	{
		// 생각 시간
		// if 왼쪽 포크가 있으면,
		// pthread_muxtex_lock(왼쪽 포크);
		// if 오른쪽 포크가 있으면,
		// pthread_muxtex_lock(오른쪽 포크);
		// 식사 타임
		// pthread_mutex_unlock(왼쪽 포크);
		// pthread_mutex_unlock(오른쪽 포크);
		// 식사 끝나면자는 시간
	}
	return (p);
}

int	main(int argc, char **argv)
{
	t_simul	simul;

	if (!init_simul(&simul, argc, argv) || !init_pthread(&simul))
		return (-1);
	// mutex_destroy 필요
	return (0);
}
