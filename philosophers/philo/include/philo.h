/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:55:38 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/22 19:56:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define THINK 0
# define EAT 1
# define SLEEP 2

typedef struct s_philo
{
	int	life;
	int	fork;
	int	status;
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
	t_philo			*philo;
}	t_simul;

// tools0.c
int	ft_atoi(char *str);

// init.c
int		init_simul(t_simul *simul, int argc, char **argv);
void	init_philo(t_simul *simul);
int		init_pthread(t_simul *simul);

void	*philo_survive(void *p);

#endif
