#include "../philosophers.h"

long	get_start_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}

long	get_current_time(long start_time)
{
	struct timeval	tp_start;
	long			current_time;

	gettimeofday(&tp_start, NULL);
	current_time = tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000;
	return (current_time - start_time);
}
