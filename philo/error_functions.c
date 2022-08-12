/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:47:17 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/05 23:37:47 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	check_args(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
	{
		write(2, "Wrong Arguments !\n", 18);
		return (1);
	}
	if (check_empty(argc, argv))
		return (1);
	else if (check_numbers(argc, argv))
		return (1);
	else if (ft_atoi(argv[1]) == 0)
	{
		write(2, "N of philos must be greater than 0 !\n", 37);
		return (1);
	}
	return (0);
}

int	check_empty(int argc, char **argv)
{
	if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0'
			|| argv[4][0] == '\0' || (argc == 6 && argv[5][0] == '\0'))
	{
		write(2, "Wrong Arguments !\n", 18);
		return (1);
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write(2, "Wrong Arguments !\n", 18);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
