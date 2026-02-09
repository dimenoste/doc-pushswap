/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInOption.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:43 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:28:47 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In OptionState
void	letterWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInOptionState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	spaceWhenInOption(contextState *currState)
{
	char	*option_found;
	int		is_option_found;
	int		is_bench_found;

	is_option_found = -1;
	is_bench_found = -1;
	printf("============================================\n");
	is_option_found = extract_option_in_state(currState);
	is_bench_found = extract_bench_in_state(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (is_option_found == 0 && is_bench_found == 0)
	{
		toInInvalidState(currState);
	}
	else
	{
		toInSpaceState(currState);
	}
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
	// verify option
}

void	digitWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash != 2)
		toInInvalidState(currState);
	else
		toInDashState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInOption(contextState *currState)
{
	char *option_found;
	int is_option_found;
	int is_bench_found;

	is_option_found = -1;
	is_bench_found = -1;
	printf("============================================\n");
	is_option_found = extract_option_in_state(currState);
	is_bench_found = extract_bench_in_state(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (is_option_found == 0 && is_bench_found == 0)
	{
		toInInvalidState(currState);
	}
	else if (!currState->option_found)
	{
		toInInvalidState(currState);
	}
	else
		toEndSuccess(currState);
	printf("end has been reached : END OF PROGRAM\n");
	printf("============================================\n");
}