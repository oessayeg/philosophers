/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:03:47 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/08 17:53:03 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

t_params	*init_parameters(int argc, char **argv)
{
	t_params	*par;

	par = malloc(sizeof(t_params));
	if (!par)
	{
		write(2, "Malloc Failed !\n", 16);
		return (NULL);
	}
	par->n_philo = ft_atoi(argv[1]);
	par->time_to_die = ft_atoi(argv[2]);
	par->time_to_eat = ft_atoi(argv[3]);
	par->time_to_sleep = ft_atoi(argv[4]);
	par->n_meals = 0;
	par->sim_start = give_time();
	if (argc == 6)
		par->n_meals = ft_atoi(argv[5]);
	sem_unlink("/sem");
	sem_unlink("/print");
	par->forks = sem_open("/sem", O_CREAT, 0644, par->n_philo);
	par->print_sem = sem_open("/print", O_CREAT, 0644, 1);
	return (par);
}

t_philo	*init_philo(t_params *param)
{
	int		i;
	t_philo	*ret_struct;

	i = -1;
	ret_struct = malloc(sizeof(t_philo) * param->n_philo);
	if (ret_struct == NULL)
		return (NULL);
	while (++i < param->n_philo)
	{
		ret_struct[i].philo_id = i + 1;
		ret_struct[i].last_eat = 0;
		ret_struct[i].eaten_meals = 0;
		ret_struct[i].par = param;
		ret_struct[i].is_put = 1;
	}
	return (ret_struct);
}
