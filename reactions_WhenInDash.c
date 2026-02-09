/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInDash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:52:54 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:52:55 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In InDash
void	letterWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInOptionState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInDash(contextState *currState)
{
	letterWhenInStart(currState);
}

void	spaceWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash == 1)
	{
		currState->start_number = currState->addr_first_dash;
		toInNumberState(currState);
		currState->nber_dash = 0;
	}
	else if (currState->nber_dash == 0)
	{
		currState->start_number;
		toInNumberState(currState);
		currState->nber_dash = 0;
	}
	else
		toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	// reset dash counter to 0
	printf("============================================\n");
}

void	dashWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash < 2)
	{
		toInDashState(currState);
	}
	else
		toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("============================================\n");
}