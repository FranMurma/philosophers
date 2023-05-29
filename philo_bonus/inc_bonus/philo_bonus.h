/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:34:25 by frmurcia          #+#    #+#             */
/*   Updated: 2023/05/29 17:00:45 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "colors_bonus.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pthread.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				name;
	sem_t			*fork;
	sem_t			*eat;
	sem_t			*print;
	long long int	last_meal;
	int				need_eat;
	int				philo_nb;
	long long int	time_die;
	long long int	time_eat;
	long long int	time_sleep;
	int				times_must_eat;
	long long int	time_start;
	long long int	current_time;
	pid_t			*pid;
	int				argc6;
}	t_philo;

//philo_auxil.c
int				ft_atoi(const char *str);
int				ft_strlen(char *string);

//philo_check_bonus.c  -- Check of argc and argv
void			ft_print_error(t_philo *philo);
int				ft_check_argc(int argc, t_philo *philo);
int				ft_check_5(char **argv, t_philo *philo);
int				ft_check_argv(char **argv, t_philo *philo);
int				ft_checks(t_philo *philo, int argc, char **argv);

//philo_init_bonus.c
void			ft_print_values_errors(t_philo *philo);
int				ft_init_philo(t_philo *philo, int argc, char **argv);
int				ft_init_sems(t_philo *philo);
int				ft_init_all(t_philo *philo, int argc, char **argv);

//philo_start_bonus.c
int				ft_start_process(t_philo *philo);
int				ft_start_routine(t_philo *philo, int nb);
int				ft_check_if_dead(t_philo *philo);
int				ft_kill_them_all(t_philo *philo, int pid);

//philo_routine_bonus.c
void			*ft_routine(void *cast_philo);
void			ft_sleep_thing(t_philo *philo);
void			ft_eat(t_philo *philo);

//philo_time_bonus.c
long long int	ft_get_current_time(void);
void			ft_usleep(int nbr);
long long int	ft_time_from_last_meal(t_philo *philo);

//philo_print_bonus.c
void			ft_print_one(t_philo *philo, int name, char *text1);
void			ft_print_action(t_philo *philo, int name, char *text1);
void			ft_print_sleep_think(t_philo *philo, int name,
					char *text, char *text2);
void			ft_print_end(t_philo *philo, char *text);
void			ft_print_death(t_philo *philo, long long int time,
					int name, char *text);

//philo_close_bonus.c
void			ft_delete_sems(t_philo *philo);

#endif
