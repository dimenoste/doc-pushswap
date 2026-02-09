/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInStart.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:52:48 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:52:49 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In Start
void	letterWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", currState->name_state);
	toInInvalidState(currState);
	printf("current state is : %s\n", currState->name_state);
	printf("============================================\n");
}

void	otherWhenInStart(contextState *currState)
{
	letterWhenInStart(currState);
}

void	spaceWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInSpaceState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInNumberState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInDashState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("end has been reached : END OF PROGRAM\n");
	toEndSuccess(currState);
	printf("============================================\n");
}