/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:38:43 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/25 16:06:08 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print_action(t_data *data, int name, char *text)
{
	pthread_mutex_lock(&data->mute_print);
	if (data->death == 0)
	{
		printf(YELLOW "Time %lli: \t", ft_get_current_time() - data->time_start);
		printf(GREEN "The philosopher number: ");
		printf(RED"%d\t", name);
		printf(GREEN "%s\n", text);
	}
	pthread_mutex_unlock(&data->mute_print);
}

void	ft_print_death(t_data *data, int name, char *text)
{
	pthread_mutex_lock(&data->mute_print);
	if (data->death == 0)
	{
		printf(YELLOW "Time %lli:  ", ft_get_current_time() - data->time_start);
		printf(RED "The filosopher number:  %d ", name);
		printf(ORANGE "%s\n", text);
	}
}

void	ft_print_end(t_data *data, char *text)
{
	printf(YELLOW "Time %lli!! ", ft_get_current_time() - data->time_start);
	printf(GREEN "%s\n", text);
}

void	ft_print_sleep_think(t_data *data, int name, char *text, char *text2)
{
	pthread_mutex_lock(&data->mute_print);
	if (data->death == 0)
	{
		printf(YELLOW "Time %lli:\t", ft_get_current_time() - data->time_start);
		printf(GREEN "The philosopher number: ");
		printf(RED"%d\t", name);
		printf(GREEN "%s\n", text);
		printf(YELLOW "Time %lli:\t", ft_get_current_time() - data->time_start);
		printf(GREEN "The philosopher number: ");
		printf(RED"%d\t", name);
		printf(GREEN "%s\n", text2);
	}
	pthread_mutex_unlock(&data->mute_print);
}
