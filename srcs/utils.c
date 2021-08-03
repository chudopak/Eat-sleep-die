#include "../philosophers.h"

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
