/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInOption2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:45:28 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/13 21:20:41 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_option(t_context *currState, t_states *mystates)
{
	printf("=================== digit_when_in_option =========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("==================== digit_when_in_option ========================\n");
}

void	dash_when_in_option(t_context *currState, t_states *mystates)
{
	printf("================== dash_when_in_option =========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash != 2)
		toin_invalid_state(currState, mystates);
	else
		toin_dash_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("=================== dash_when_in_option =========================\n");
}

void	end_when_in_option(t_context *currState, t_states *mystates)
{
	int	is_option_found;
	int	is_bench_found;

	is_option_found = -1;
	is_bench_found = -1;
	printf("================ end of string has been reached ============================\n");
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
	printf("=================== end_when_in_option =========================\n");
}
