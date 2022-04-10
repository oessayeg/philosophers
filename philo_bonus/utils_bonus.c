/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:50:50 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/06 13:13:49 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

int	ft_atoi(char *nb)
{
	int	i;
	int	return_value;

	return_value = 0;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		return_value = return_value * 10 + (nb[i] - 48);
		i++;
	}
	return (return_value);
}

long int	give_time(void)
{
	struct timeval	st;

	gettimeofday(&st, NULL);
	return ((st.tv_sec * 1000) + (st.tv_usec / 1000));
}

void	print_msg(t_philo *philo, int option)
{
	sem_wait(philo->par->print_sem);
	printf("%ld ", give_time() - philo->par->sim_start);
	if (option == 1)
		printf("%d has taken a fork\n", philo->philo_id);
	else if (option == 2)
	{
		printf("%d is eating\n", philo->philo_id);
		philo->eaten_meals += 1;
	}
	else if (option == 3)
		printf("%d is sleeping\n", philo->philo_id);
	else if (option == 4)
		printf("%d is thinking\n", philo->philo_id);
	else
	{
		print_msg2(philo, option);
		return ;
	}
	sem_post(philo->par->print_sem);
}

void	print_msg2(t_philo *philo, int option)
{
	if (option == 5)
		printf("%d died\n", philo->philo_id);
	else if (option == 6)
		printf("Simulation has ended\n");
}

void	n_sleep(int time)
{
	long int	n;

	n = give_time() + time;
	while (give_time() < n)
		usleep(200);
}
