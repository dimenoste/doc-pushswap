/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInOption2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:45:28 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 22:50:22 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_option(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dash_when_in_option(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash != 2)
		toin_invalid_state(currState, mystates);
	else
		toin_dash_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	end_when_in_option(t_context_state *currState,
		t_implement_handlers *mystates)
{
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
		toin_invalid_state(currState, mystates);
	}
	else if (!currState->option_found)
	{
		toin_invalid_state(currState, mystates);
	}
	else
		to_end_success(currState, mystates);
	printf("end has been reached : END OF PROGRAM\n");
	printf("============================================\n");
}
