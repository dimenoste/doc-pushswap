/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniatize_states1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:52:03 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 17:52:16 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_implement_handlers	*init_state_start(t_implement_handlers *mystates)
{
	mystates->InStartState->handler_letter = &letterWhenInStart;
	mystates->InStartState->handler_space = &spaceWhenInStart;
	mystates->InStartState->handler_digit = &digitWhenInStart;
	mystates->InStartState->handler_dash = &dashWhenInStart;
	mystates->InStartState->handler_other = &otherWhenInStart;
	mystates->InStartState->handler_end = &endWhenInStart;
	return (mystates);
}

t_implement_handlers	*init_state_dash(t_implement_handlers *mystates)
{
	mystates->InDashState->handler_letter = &letterWhenInDash;
	mystates->InDashState->handler_space = &spaceWhenInDash;
	mystates->InDashState->handler_digit = &digitWhenInDash;
	mystates->InDashState->handler_dash = &dashWhenInDash;
	mystates->InDashState->handler_other = &otherWhenInDash;
	mystates->InDashState->handler_end = &endWhenInDash;
	return (mystates);
}

struct toto	*init_state_space(t_implement_handlers *mystates)
{
	mystates->InOptionState->handler_letter = &letterWhenInOption;
	mystates->InOptionState->handler_space = &spaceWhenInOption;
	mystates->InOptionState->handler_digit = &digitWhenInOption;
	mystates->InOptionState->handler_dash = &dashWhenInOption;
	mystates->InOptionState->handler_other = &otherWhenInOption;
	mystates->InOptionState->handler_end = &endWhenInOption;
	return (mystates);
}

t_implement_handlers	*init_state_number(t_implement_handlers *mystates)
{
	mystates->InNumberState->handler_letter = &letterWhenInNumber;
	mystates->InNumberState->handler_space = &spaceWhenInNumber;
	mystates->InNumberState->handler_digit = &digitWhenInNumber;
	mystates->InNumberState->handler_dash = &dashWhenInNumber;
	mystates->InNumberState->handler_other = &otherWhenInNumber;
	mystates->InNumberState->handler_end = &endWhenInNumber;
	return (mystates);
}

t_implement_handlers	*init_state_number(t_implement_handlers *mystates)
{
	mystates->InNumberState->handler_letter = &letterWhenInNumber;
	mystates->InNumberState->handler_space = &spaceWhenInNumber;
	mystates->InNumberState->handler_digit = &digitWhenInNumber;
	mystates->InNumberState->handler_dash = &dashWhenInNumber;
	mystates->InNumberState->handler_other = &otherWhenInNumber;
	mystates->InNumberState->handler_end = &endWhenInNumber;
	return (mystates);
}