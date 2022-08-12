/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:06:47 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:38:16 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_msg2(int option, t_philo *philo)
{
	if (option == 5)
		printf("%d died\n", philo->philo_id);
	else if (option == 6)
		printf("Simulation has ended\n");
}
