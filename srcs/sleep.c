#include "../philosophers.h"

void	_usleep(int milliseconds, int start_time)
{
	time_t	stop;
	time_t	start;

	stop = get_current_time(start_time) + milliseconds;
	start = get_current_time(start_time);
	while (start < stop)
	{
		usleep(25);
		start = get_current_time(start_time);
	}
}

void	_sleep(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->all->right_to_write);
	printf("%ld\tPhilo %d is sleeping\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->all->right_to_write);
	_usleep(philo->all->input.time_to_sleep, philo->all->start_time);
}
