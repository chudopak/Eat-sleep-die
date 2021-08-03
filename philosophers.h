#ifndef PHILOSOPHERS
# define PHILOSOPHERS

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_input
{
	bool	is_valid_input;
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_of_times_to_eat;
}	t_input;


typedef struct s_all {
	t_input		input;
}				t_all;

/*
** Prepare to multithreading
*/
void	set_all(t_all *all, int nb_of_args, char **args);
void	set_input(t_input *input, int nb_of_args, char **args);

/*
** Utils
*/
long	ft_atoi(const char *arr);
int		get_input_value(char *arg, char *error_msg);

#endif