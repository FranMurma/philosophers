/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:03:37 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 15:01:44 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				name;
	int				right_fork;
	int				left_fork;
	long long int	last_meal;
	int				need_eat;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				philo_nb;
	long long int	time_die;
	long long int	time_eat;
	long long int	time_sleep;
	int				times_must_eat;
	pthread_mutex_t	mute_death;
	pthread_mutex_t	*mute_forks;
	pthread_mutex_t	mute_print;
	t_philo			*philo;
	long long int	current_time;
	long long int	time_start;
	int				death;
}	t_data;

//philo_auxil.c
int				ft_atoi(const char *str);

//philo_check.c  -- Check of argc and argv
void			ft_print_error(void);
int				ft_check_argc(int argc);
int				ft_check_argv(char **argv, t_data *data);

//philo_init.c
int				ft_init_data(t_data *data, int argc, char **argv);
int				ft_init_philo(t_data *data);
int				ft_init_mutex(t_data *data);
int				ft_init_all(t_data *data, int argc, char **argv);

//philo_create.c
int				ft_die(t_data *data);
int				ft_routine_finish(t_data *data);
void			ft_check_if_finish(t_data *data);
int				ft_create_pthread(t_data *data);

//philo_routine.c
void			*ft_start_routine(void *arg);
int				ft_one_philo(t_philo *philo);
int				ft_eat(t_philo *philo);

//philo_time.c
long long int	ft_get_current_time(void);
void			ft_usleep(int nbr);

//philo_print.c
void			ft_print_action(t_data *data, int name, char *text);
void			ft_print_death(t_data *data, int name, char *text);
void			ft_print_end(t_data *data, char *text);
void			ft_print_sleep_think(t_data *data, int name,
					char *text, char *text2);

//philo_end.c
void			ft_end(t_data *data);

#endif
