/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:37:49 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 17:22:30 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

int		ft_check_5(char **argv, t_philo *philo)
{
	int	c;
	int	len;

	c = 0;
	if (argv[5])
	{
		while (argv[5])
		{
			if (argv[5][c] >= '0' && argv[5][c] <= '9')
				c++;
			else
			{
				ft_print_error(philo);
				return (-1);
			}
		}
		len = ft_strlen(argv[5]);
		if (c == len)
		{
			printf("Error\nNothing to eat!!");
			return (-1);
		}
	}
	return (0);
}

void	ft_print_error(t_philo *philo)
{
	printf ("Error\nPlease enter the right numbers!\n");
}

int	ft_check_argc(int argc, t_philo *philo)
{
	if (argc < 5 || argc > 6)
	{
		ft_print_error(philo);
		return (-1);
	}
	return (0);
}

int	ft_check_argv(char **argv, t_philo *philo)
{
	int	count;
	int	c;

	c = 0;
	count = 1;
	if (argv[1] <= 0)
		return (-1);
	while (argv[count])
	{
		c = 0;
		while (argv[count][c])
		{
			if (argv[count][c] < '0' || argv[count][c] > '9')
				return (-1);
			c++;
		}
		count++;
	}
	return (0);
}

int	ft_checks(t_philo *philo, int argc, char **argv)
{
	if (ft_check_argc(argc, philo) == -1)
	{
		ft_print_error(philo);
		return (-1);
	}
	if (ft_check_argv(argv, philo) == -1)
	{
		ft_print_error(philo);
		return (-1);
	}
	if (ft_check_5(argv, philo) == -1)
		return (-1);
	return (0);
}
