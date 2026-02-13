/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInNumber1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:30:19 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/13 21:19:52 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In in_number_state
void	letter_when_in_number(t_context *currState, t_states *mystates)
{
	printf("================== letter_when_in_number==========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("=================== letter_when_in_number =========================\n");
}

void	other_when_in_number(t_context *currState, t_states *mystates)
{
	printf("================ other_when_in_number ============================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("==================== other_when_in_number ========================\n");
}

void	space_when_in_number(t_context *currState, t_states *mystates)
{
	t_number	result;

	printf("================ space_when_in_number ============================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("from space_when_in_number, start number is  : %s\n",
		currState->start_number);
	result = ft_patol(currState->start_number);
	if (!result.error)
	{
		currState->candidate_number = result.number;
		toin_space_state(currState, mystates);
		printf("number found after a space : %ld\n", result.number);
	}
	else
		toin_invalid_state(currState, mystates);
	// add number to linked list
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("==================== space_when_in_number ========================\n");
}
