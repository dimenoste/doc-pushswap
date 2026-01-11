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

int	ft_atoi(char *s)
{
	int	max;

	int i, n, sign;
	max = 2147483647;
	n = i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != 0)
	{
		if ((n > (max - (int)(s[i] - '0')) / 10) && sign == 1)
			return (0);
		if ((n > (max - (int)(s[i] - '1')) / 10) && sign == -1)
			return (0);
		if (s[i] < 48 || s[i] > 57)
			return (0);
		n = n * 10 + (int)(s[i] - '0');
		i++;
	}
	return (sign * n);
}



int	main(void)
{
	char	*s1;
	int		i;
	char	*s2;
	int		n;

	s1 = "--adaptive";
	i = 0;
	i = ft_strcmp(s1, "--adaptive");
	printf("cmp is %i\n", i);
	i = check_strat_selector(s1);
	printf("is it a legit strat? %i\n", i);
	s2 = "2147483647";
	n = ft_atoi(s2);
	printf("my number is %d\n", n);
	return (0);
}


