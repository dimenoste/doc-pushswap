#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

int	check_strat_selector(char *s)
{
	int		i;
	char	*strats[5] = {"--simple", "--medium", "--complex", "--adaptive", 0};

	i = 0;
	while (strats[i] != 0)
	{
		printf("my strat is %s\n", strats[i]);
		if (ft_strcmp(s, strats[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
/*
 * is_valid_strategy - Checks if string is a valid strategy flag
 *
 * Return: 1 if valid, 0 otherwise
 */
int	is_valid_strategy(char *s)
{
	if (ft_strcmp(s, "--simple"))
		return (1);
	if (ft_strcmp(s, "--medium"))
		return (1);
	if (ft_strcmp(s, "--complex"))
		return (1);
	if (ft_strcmp(s, "--adaptive"))
		return (1);
	return (0);
}
/*
 * ft_atoi_safe - Converts string to int with overflow detection
 *
 * Return: Converted number, or 0 on error (set error flag if needed)
 */
long	ft_atoi_safe(char *s, int *error)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (*error = 1, 0);
		n = n * 10 + (s[i] - '0');
		if ((sign == 1 && n > 2147483647) ||
			(sign == -1 && n > 2147483648))
			return (*error = 1, 0);
		i++;
	}
	return (sign * n);
}
