/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:28:54 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/25 18:45:22 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mute_forks[philo->left_fork]);
	ft_print_action(philo->data, philo->name,
		"has taken the left fork.");
	pthread_mutex_lock(&philo->data->mute_forks[philo->right_fork]);
	ft_print_action(philo->data, philo->name,
		"has taken the right fork.");
	ft_print_action(philo->data, philo->name, "is eating.");
	philo->last_meal = ft_get_current_time() - philo->data->time_start;
	philo->need_eat++;
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->data->mute_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->mute_forks[philo->right_fork]);
	return (0);
}

int	ft_sleep_think(t_philo *philo)
{
	ft_print_sleep_think(philo->data, philo->name,
		"is sleeping.", "is thinking.");
	ft_usleep(philo->data->time_sleep);
	return (0);
}

int	ft_one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mute_forks[philo->left_fork]);
	ft_print_action(philo->data, 1, "has taken the left fork.");
	ft_usleep(philo->data->time_die + 1);
	pthread_mutex_unlock(&philo->data->mute_forks[philo->left_fork]);
	return (-1);
}

void	*ft_start_routine(void *arg)
{
	t_philo	*philo;
	int		c;

	c = 0;
	philo = (t_philo *)arg;
	ft_usleep(philo->data->time_start - ft_get_current_time());
	if (philo->name % 2 == 0)
		ft_usleep(philo->data->time_eat / 2);
	philo->last_meal = ft_get_current_time() - philo->data->time_start;
	while (philo->data->death == 0)
	{
		if (philo->data->philo_nb == 1)
		{
			ft_one_philo(philo);
			break ;
		}
		ft_eat(philo);
		ft_sleep_think(philo);
	}
	c = 0;
	while (c < philo->data->philo_nb)
		pthread_mutex_unlock(&philo->data->mute_forks[c++]);
	return (0);
}
