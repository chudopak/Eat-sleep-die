#include "../philosophers.h"

bool	is_philo_alive(t_all *all, int i)
{
	if (all->philosopher[i].time_to_die < get_current_time(all->start_time))
	{
		pthread_mutex_lock(&all->right_to_write);
		printf("%ld\tPhilosopher %d is dead\n",
			get_current_time(all->start_time), i + 1);
		return (true);
	}
	return (false);
}

void	threads_monitoring(t_all *all)
{
	int		i;
	int		full_philosophers;

	while (1)
	{
		i = 0;
		full_philosophers = 0;
		while (i < all->input.number_of_philo)
		{
			pthread_mutex_lock(&all->philosopher[i].right_to_eat);
			if (all->philosopher[i].eaten_meals >= all->input.meal_intake)
				full_philosophers++;
			if (is_philo_alive(all, i))
				return ;
			pthread_mutex_unlock(&all->philosopher[i].right_to_eat);
			i++;
		}
		if (full_philosophers == all->input.number_of_philo)
		{
			pthread_mutex_lock(&all->right_to_write);
			return ;
		}
		usleep(100);
	}
}

void	*eat_sleep_think(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	start_threads(t_all *all)
{
	int			i;
	pthread_t	thread_id;

	i = 0;
	while (i < all->input.number_of_philo)
	{
		if (pthread_create(&thread_id, NULL,
				eat_sleep_think, (void *)(all->philosopher + i)))
		{
			pthread_mutex_lock(&all->right_to_write);
			printf("Could not create a thread for %d philosopher\n", i);
			return ;
		}
		pthread_detach(thread_id);
		i++;
	}
	threads_monitoring(all);
}

int	main(int ac, char **av)
{
	t_all	all;

	set_all(&all, ac - 1, av + 1);
	if (all.error_status == false)
		start_threads(&all);
	free_all(&all);
	return (0);
}
