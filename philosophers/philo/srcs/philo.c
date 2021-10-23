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

int	main(int argc, char **argv)
{
	t_simul	simul;

	if (argc < 5 || argc > 6)
		return (-1);
	if (!init_simul(&simul, argc, argv) || !init_pthread_mutex(&simul))
		return (-1);
	if (!wait_mornitor(&simul))
		return (-1);
	free(simul.mutex);
	free(simul.philo);
	free(simul.thread);
	return (0);
}
