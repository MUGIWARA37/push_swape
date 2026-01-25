#include <limits.h>

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (unsigned long)LONG_MAX + (sign == -1))
			return (sign == -1 ? LONG_MIN : LONG_MAX);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((long)(result * sign));
}
