/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:36:33 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/12 12:56:16 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	init_vars_patol(t_vars_ft_patols *vars)
{
	vars->max = 2147483647;
	vars->i = 0;
	vars->n = 0;
	vars->sign = 1;
}

int	is_digit_within_limits(char *s, t_vars_ft_patols *vars)
{
	return (((vars->n > (vars->max - (int)(s[vars->i] - '0')) / 10)
			&& vars->sign == 1) || ((vars->n > (vars->max - (int)(s[vars->i]
						- '1')) / 10) && vars->sign == -1) || (s[vars->i] < 48
			|| s[vars->i] > 57));
}

t_number	ft_patol(char *s)
{
	t_vars_ft_patols	*vars;
	t_number			output;

	output.error = 1;
	output.number = 0;
	vars = NULL;
	init_vars_patol(vars);
	printf("from ft_patol, number to process  is |%s|\n", s);
	if (s[vars->i] == '-')
	{
		vars->sign = -1;
		vars->i += 1;
	}
	while (s[vars->i] != '\0' && s[vars->i] != ' ')
	{
		printf("from ft_patol, current char  is |%c|\n", s[vars->i]);
		if (is_digit_within_limits(s, vars))
		{
			printf("from ft_patol, error case :  ccurrent char  is |%c|\n",
				s[vars->i]);
			return (output);
		}
		vars->n = vars->n * 10 + (int)(s[vars->i] - '0');
		vars->i++;
	}
	printf("from ft_patol, output number is |%ld|\n", output.number);
	output.number = vars->sign * vars->n;
	output.error = 0;
	return (output);
}

int	ft_strcmp_space(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	char	*bench;

	bench = "--bench";
	printf("== FROM get_bench_selector ==, s passed is :%s\n", s);
	if (ft_strcmp_space(s, bench) == 1)
	{
		return (bench);
	}
	return (NULL);
}
const char	*get_state_name(t_enum_state_name enum_name)
{
	const char *statesNames[] = {"in_start_state", "in_dash_state",
		"in_option_state", "in_space_state", "in_invalid_state",
		"in_number_state", "in_success_state"};

	return (statesNames[enum_name]);
}