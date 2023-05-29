/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:59:58 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/24 15:57:50 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	ft_print_one(t_philo *philo, int name, char *text1)
{
	printf(YELLOW "Time %lli: \t" GREEN "The philosopher number:  " RED "%d\t"
		GREEN "%s\n", ft_get_current_time() - philo->time_start, name, text1);
	exit (1);
}

void	ft_print_action(t_philo *philo, int name, char *text1)
{
	printf(YELLOW "Time %lli: \t" GREEN "The philosopher number: " RED "%d\t"
		GREEN "%s\n", ft_get_current_time() - philo->time_start, name, text1);
	if (philo->philo_nb == 1)
		ft_usleep(philo->time_die);
}

void	ft_print_death(t_philo *philo, long long int time, int name, char *text)
{
	printf(YELLOW "Time: %lli\t", time);
	printf(RED "The filosopher number:  %d \t", philo->name);
	printf(ORANGE "%s\n", text);
	exit (1);
}

void	ft_print_end(t_philo *philo, char *text)
{
	sem_wait(philo->print);
	printf(YELLOW "Time %lli!! ", ft_get_current_time() - philo->time_start);
	printf(GREEN "%s\n", text);
	sem_post(philo->print);
}

void	ft_print_sleep_think(t_philo *philo, int name, char *text, char *text2)
{
	printf(YELLOW "Time %lli:\t", ft_get_current_time() - philo->time_start);
	printf(GREEN "The philosopher number: ");
	printf(RED"%d\t", name);
	printf(GREEN "%s\n", text);
	printf(YELLOW "Time %lli:\t", ft_get_current_time() - philo->time_start);
	printf(GREEN "The philosopher number: ");
	printf(RED"%d\t", name);
	printf(GREEN "%s\n", text2);
}
