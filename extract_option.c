/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:53:44 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:53:07 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extract_option_in_state(t_context *currState)
{
	char	*candidate_option;

	candidate_option = get_strat_selector(currState->addr_first_dash);
	if (!currState->option_found && candidate_option)
	{
		currState->option_found = candidate_option;
		return (1);
	}
	else
		return (0);
}

int	extract_bench_in_state(t_context *currState)
{
	char	*candidate_bench;

	candidate_bench = get_bench_selector(currState->addr_first_dash);
	if (!currState->bench_found && candidate_bench)
	{
		currState->bench_found = candidate_bench;
		return (1);
	}
	else
		return (0);
}
