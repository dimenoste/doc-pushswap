/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInStart2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:52:37 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/15 19:15:10 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_start(t_context *currState, t_states *mystates)
{
	printf("==================== digit_when_in_start ========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_number_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("====================== digit_when_in_start ======================\n");
}

void	dash_when_in_start(t_context *currState, t_states *mystates)
{
	printf("=================== dash_when_in_start =========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_dash_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("====================== dash_when_in_start ======================\n");
}

void	end_when_in_start(t_context *currState, t_states *mystates)
{
	printf("=============== end_when_in_start  =============================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	to_end_success(currState, mystates);
	printf("===================== end_when_in_start =======================\n");
}
