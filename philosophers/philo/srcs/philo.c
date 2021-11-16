/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:20:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/24 00:22:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	free_simul(t_simul *simul, int fr, int er)
{
	if (fr)
	{
		free(simul->mutex);
		free(simul->philo);
		free(simul->thread);
	}
	if (er)
		printf("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_simul	simul;

	if (argc < 5 || argc > 6)
		return (free_simul(&simul, 0, 1));
	if (!init_simul(&simul, argc, argv))
		return (free_simul(&simul, 0, 1));
	if (!init_pthread_mutex(&simul))
		return (free_simul(&simul, 1, 1));
	if (!wait_mornitor(&simul))
		return (free_simul(&simul, 1, 1));
	return (free_simul(&simul, 1, 0));
}
