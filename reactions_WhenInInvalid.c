/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInInvalid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:32:58 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:33:17 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In InvalidState
void	stayInInvalid(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}