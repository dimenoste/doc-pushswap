/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:36:33 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 18:12:07 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

t_number	ft_patol(char *s)
{
	int			max;
	t_number	output;

	int i, n, sign;
	max = 2147483647;
	output.error = 1;
	output.number = i = n = 0;
	sign = 1;
	printf("from ft_patol, number to process  is |%s|\n", s);
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0' && s[i] != ' ')
	{
		printf("from ft_patol, current char  is |%c|\n", s[i]);
		if (((n > (max - (int)(s[i] - '0')) / 10) && sign == 1) || ((n > (max
						- (int)(s[i] - '1')) / 10) && sign == -1) || (s[i] < 48
				|| s[i] > 57))
		{
			printf("from ft_patol, error case :  ccurrent char  is |%c|\n",
				s[i]);
			return (output);
		}
		n = n * 10 + (int)(s[i] - '0');
		i++;
	}
	printf("from ft_patol, output number is |%d|\n", output.number);
	output.number = sign * n;
	output.error = 0;
	return (output);
}

int	ft_strcmp_space(char *s1, char *s2)
{
	int i, j;
	i = j = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*get_strat_selector(char *s)
{
	int		i;
	char	*strats[5] = {"--simple", "--medium", "--complex", "--adaptive", 0};

	i = 0;
	printf("== FROM get_strat_selector ==, s passed is :%s\n", s);
	while (strats[i] != 0)
	{
		if (ft_strcmp_space(s, strats[i]) == 1)
		{
			return (strats[i]);
		}
		i++;
	}
	return (NULL);
}

char	*get_bench_selector(char *s)
{
	int		i;
	char	*bench;

	bench = "--bench";
	i = 0;
	printf("== FROM get_bench_selector ==, s passed is :%s\n", s);
	if (ft_strcmp_space(s, bench) == 1)
	{
		return (bench);
	}
	return (NULL);
}
const char	*get_state_name(e_state_name enum_name)
{
	const char *statesNames[] = {"InStartState", "InDashState", "InOptionState",
		"InSpaceState", "InInvalidState", "InNumberState", "InSuccessState"};

	return (statesNames[enum_name]);
}