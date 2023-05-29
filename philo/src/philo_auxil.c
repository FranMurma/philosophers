/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_auxil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:02:05 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/02 15:23:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	while ((unsigned char)str[i] == ' ' || (unsigned char)str[i] == '\t'
		|| (unsigned char)str[i] == '\n' || (unsigned char)str[i] == '\f'
		|| (unsigned char)str[i] == '\r' || (unsigned char)str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (sign * n);
}
