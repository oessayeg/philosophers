/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:17:24 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:37:44 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5
# define SIMU 6

typedef struct parameters
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	long int		sim_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}t_params;

typedef struct s_philosophers
{
	int			philo_id;
	int			left_fork;
	int			right_fork;
	long long	last_eat;
	int			state;
	int			eaten_meals;
	pthread_t	th;
	t_params	*rules;
}t_philo;

//Error Checking
int			check_args(int argc, char **argv);
int			check_empty(int argc, char **argv);
int			ft_isdigit(char c);
int			check_numbers(int argc, char **argv);

//Initialization
int			init_struct(int argc, char **argv, t_params *par);
t_philo		*init_philo_struct(t_params *par);

//Utils
int			m_fail(void);
int			ft_atoi(char *nb);
long int	give_time(void);
void		print_msg(t_philo *philo, int option);
void		new_sleep(int t_to_sleep);
void		print_msg2(int option, t_philo *philo);

//Threads and routines
int			init_threads(t_philo *philo);
int			one_philo(t_philo *philo);
void		*routine(void *p);
void		take_forks(t_philo *philo);
void		put_forks(t_philo *philo);

//Watcher
int			check_death_time(t_philo *philo);
int			check_meals(t_philo *philo);

#endif
