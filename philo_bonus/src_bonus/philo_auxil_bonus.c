/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_auxil_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:36:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 17:02:16 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

static bool	ft_isdigit(int c)
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

int	ft_strlen(char *string)
{
	int	c;

	c = 0;
	if (!string)
		return (0);
	while (string[c])
		c++;
	return (c);
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
