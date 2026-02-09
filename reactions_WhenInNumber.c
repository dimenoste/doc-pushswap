/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInNumber.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:30:19 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:30:44 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In InNumberState
void	letterWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}


void	spaceWhenInNumber(contextState *currState)
{
	t_number	result;

	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("from spaceWhenInNumber, start number is  : %s\n",
		currState->start_number);
	result = ft_patoi(currState->start_number);
	if (!result.error)
	{
		currState->candidate_number = result.number;
		toInSpaceState(currState);
		printf("number found after a space : %d\n", result.number);
	}
	else
		toInInvalidState(currState);
	// add number to linked list
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInNumberState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInNumber(contextState *currState)
{
	t_number result;

	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("from endWhenInNumber, number as string : %s\n",
		currState->start_number);
	result = ft_patoi(currState->start_number);
	if (result.error == 0)
	{
		currState->candidate_number = result.number;
		toEndSuccess(currState);
		printf("number found at the end : %d\n", result.number);
	}
	else
		toInInvalidState(currState);
	// add number to linked list
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}