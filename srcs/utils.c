#include "../philosophers.h"

void	free_all(t_all *all)
{
	int	i;

	i = 0;
	if (all)
	{
		while (i < all->input.number_of_philo)
		{
			pthread_mutex_destroy(&all->fork[i]);
			pthread_mutex_destroy(&all->philosopher[i].right_to_eat);
			i++;
		}
		free(all->fork);
		free(all->philosopher);
	}
	pthread_mutex_destroy(&all->right_to_write);
}

void	free_philosophers(t_philosopher *philo, int must_be_destroyed)
{
	int	i;

	i = 0;
	while (i < must_be_destroyed)
	{
		pthread_mutex_destroy(&philo[i].right_to_eat);
		i++;
	}
	free(philo);
}

void	free_forks(pthread_mutex_t *fork, int must_be_destroyed)
{
	int	i;

	i = 0;
	while (i < must_be_destroyed)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	free(fork);
}

long	ft_atoi(const char *arr)
{
	long	sign;
	long	res;

	res = 0;
	sign = 1;
	while (*arr == ' ' || *arr == '\t' || *arr == '\v' || *arr == '\f'
		|| *arr == '\r' || *arr == '\n')
		arr++;
	if (*arr == '-' || *arr == '+')
	{
		if (*arr == '-')
			sign = -1;
		arr++;
	}
	while (*arr >= '0' && *arr <= '9')
	{
		res = res * 10 + (*arr - '0');
		arr++;
	}
	return (sign * res);
}

int	get_input_value(char *arg, char *error_msg)
{
	long	valaue;

	valaue = ft_atoi(arg);
	if (valaue <= 0)
		printf("%s\n", error_msg);
	return (valaue);
}
