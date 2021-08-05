#include "../philosophers.h"

pthread_mutex_t	*set_forks(int number_of_philo)
{
	int				i;
	int				init_status;
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * number_of_philo);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < number_of_philo)
	{
		init_status = pthread_mutex_init(&fork[i], NULL);
		if (init_status)
		{
			free_forks(fork, i);
			return (NULL);
		}
		i++;
	}
	return (fork);
}

void	set_all(t_all *all, int nb_of_args, char **args)
{
	all->error_status = false;
	set_input(&(all->input), nb_of_args, args);
	if (pthread_mutex_init(&all->right_to_write, NULL))
		all->error_status = true;
	all->start_time = get_start_time();
	printf("%ld\n", all->start_time);
	all->fork = set_forks(all->input.number_of_philo);
	//all->philosopher = set_philosophers(all);
}
