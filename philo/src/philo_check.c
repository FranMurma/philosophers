/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:06:11 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 14:59:58 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print_error(void)
{
	write (2, "Error\nPlease enter the right numbers\n", 37);
}

int	ft_check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_print_error();
		return (-1);
	}
	return (0);
}

int	ft_check_argv(char **argv, t_data *data)
{
	int	count;
	int	c;

	c = 0;
	count = 1;
	if (argv[1] <= 0)
	{
		ft_print_error();
		return (-1);
	}
	while (argv[count])
	{
		c = 0;
		while (argv[count][c])
		{
			if (argv[count][c] < '0' || argv[count][c] > '9')
			{
				ft_print_error();
				free(data);
				return (-1);
			}
			c++;
		}
		count++;
	}
	return (0);
}
