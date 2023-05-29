/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:26:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 15:01:41 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	system("clear");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (ft_check_argc(argc) == -1)
		return (-1);
	if (ft_check_argv(argv, data) == -1)
		return (-1);
	if (ft_init_all(data, argc, argv) != 0)
		return (-1);
	ft_create_pthread(data);
	ft_end(data);
	return (0);
}
