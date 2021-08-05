#ifndef PHILOSOPHERS
# define PHILOSOPHERS

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>


typedef struct s_input {
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_nb_of_times_to_eat;
	bool	is_valid_input;
}	t_input;

typedef struct s_all t_all;

typedef struct s_philosopher {
	int				eaten_meals;
	time_t			time_to_die;
	t_all			*all;
	pthread_mutex_t	*first_taken_fork;
	pthread_mutex_t	*second_taken_fork;
	pthread_mutex_t	*right_to_write;
	pthread_mutex_t right_to_eat;
}	t_philosopher;


typedef struct s_all {
	long			start_time;
	bool			error_status;
	t_input			input;
	t_philosopher	*philosopher;
	pthread_mutex_t	right_to_write;
	pthread_mutex_t	*fork;
}	t_all;

/*
** Prepare to multithreading
*/
void			set_all(t_all *all, int nb_of_args, char **args);
void			set_input(t_input *input, int nb_of_args, char **args);
pthread_mutex_t	*set_forks(int number_of_philo);

/*
** Utils
*/
long			ft_atoi(const char *arr);
int				get_input_value(char *arg, char *error_msg);
void			free_forks(pthread_mutex_t *fork, int must_be_destroyed);
void			free_philosophers(t_philosopher *philo, int must_be_destroyed);

/*
** Time
*/
long			get_start_time(void);
long			get_current_time(long start_time);

#endif