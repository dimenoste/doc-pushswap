/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInNumber2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:54 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/14 18:37:44 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_number(t_context *currState, t_states *mystates)
{
	printf("================== digit_when_in_number ==========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_number_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("================== digit_when_in_number ==========================\n");
}

void	dash_when_in_number(t_context *currState, t_states *mystates)
{
	printf("=================== dash_when_in_number =========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("=================== dash_when_in_number =========================\n");
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
		stack_add_back(currState->parsed_stack, new_node(result.number));
		print_stack(currState->parsed_stack,
			"number found from space_when_in_number");
	}
	else
		toin_invalid_state(currState, mystates);
	// add number to linked list
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("==================== space_when_in_number ========================\n");
}

void	end_when_in_number(t_context *currState, t_states *mystates)
{
	t_number	result;

	printf("================== end_when_in_number ==========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("from end_when_in_number, number as string : %s\n",
		currState->start_number);
	result = ft_patol(currState->start_number);
	if (result.error == 0)
	{
		currState->candidate_number = result.number;
		to_end_success(currState, mystates);
		printf("number found at the end : %ld\n", result.number);
		stack_add_back(currState->parsed_stack, new_node(result.number));
		print_stack(currState->parsed_stack,
			"number found from end_when_in_number");
	}
	else
		toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("==================== end_when_in_number ========================\n");
}
