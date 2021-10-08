/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:55:38 by minskim2          #+#    #+#             */
/*   Updated: 2021/10/08 17:11:16 by minskim2         ###   ########.fr       */
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
# define FORK 1
# define EAT 2
# define SLEEP 3
# define DIE 4

typedef struct s_philo
{
	int				philo_num;
	int				num;
	int				life;
	size_t			age;
	int				fork;
	int				status;
	int				change;
	int				time_eat;
	int				time_sleep;
	int				time_opt;
	int				num_eat;
	int				end_eat;
	int				end_game;
	int				*start_point;
	pthread_mutex_t	*mutex;
	struct timeval	last_eat;
}	t_philo;

typedef struct s_simul
{
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_opt;
	int				start_point;
	int				end;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	t_philo			*philo;
}	t_simul;

// tools0.c
int	ft_atoi(char *str);

// init.c
int		init_simul(t_simul *simul, int argc, char **argv);
void	init_philo(t_simul *simul);
int		init_pthread_mutex(t_simul *simul);
// pthread.c
void	print_msg(t_philo *philo);
void	*running_pthread(void *p);
void	*mornitor_pthread(void *s);
void	*running_pthread(void *p);
int		wait_pthread(t_simul *simul);

#endif
