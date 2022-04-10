/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:58:55 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/06 13:14:09 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_params
{
	int			n_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_meals;
	long int	sim_start;
	sem_t		*forks;
	sem_t		*print_sem;
}t_params;

typedef struct s_philosophers
{
	int			philo_id;
	long int	last_eat;
	int			eaten_meals;
	int			is_put;
	pid_t		process_id;
	pthread_t	th;
	t_params	*par;
}t_philo;

//Error handling
int			check_args(int argc, char **argv);
int			check_empty(int argc, char **argv);
int			f_isdigit(char c);
int			check_numbers(int argc, char **argv);

//Initialization
t_params	*init_parameters(int argc, char **argv);
t_philo		*init_philo(t_params *param);

//Utils
int			ft_atoi(char *nb);
long int	give_time(void);
void		print_msg(t_philo *philo, int option);
void		print_msg2(t_philo *philo, int option);
void		n_sleep(int time);

//Routine
int			init_processes(t_philo *philos);
void		philo_routine(t_philo *philo);
void		take_forks(t_philo *philo);
void		put_forks(t_philo *philo);

//Watcher
void		*thread_watcher(void *p);

//Waiting
void		wait_processes(t_philo *philo);

#endif
