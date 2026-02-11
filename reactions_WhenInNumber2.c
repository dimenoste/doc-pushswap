/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInNumber2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:54 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 22:44:07 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_number(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_number_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dash_when_in_number(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	end_when_in_number(t_context_state *currState,
		t_implement_handlers *mystates)
{
	t_number	result;

	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("from end_when_in_number, number as string : %s\n",
		currState->start_number);
	result = ft_patol(currState->start_number);
	if (result.error == 0)
	{
		currState->candidate_number = result.number;
		to_end_success(currState, mystates);
		printf("number found at the end : %ld\n", result.number);
	}
	else
		toin_invalid_state(currState, mystates);
	// add number to linked list
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}
