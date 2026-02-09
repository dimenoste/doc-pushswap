/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInSpace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:08 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:28:24 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In SpaceState
void	letterWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	spaceWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInSpaceState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInNumberState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInDashState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("end has been reached : END OF PROGRAM\n");
	toEndSuccess(currState);
	printf("============================================\n");
}
