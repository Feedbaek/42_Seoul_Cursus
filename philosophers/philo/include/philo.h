/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:55:38 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/21 21:42:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int	life;
	int	fork;
}	t_philo;

typedef struct s_simul
{
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_opt;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
}	t_simul;

int	ft_atoi(char *str);

#endif
