/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:41:38 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:41:51 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	classify_input(contextState *mystate)
{
	char	input;

	input = *(mystate->mystring);
	if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		return (mystate->interface->handler_letter(mystate));
	else if (input >= '0' && input <= '9')
	{
		printf("from classify_input, inpur is a number : %c\n", input);
		if (mystate->nber_digits == 0)
			mystate->start_number = mystate->mystring;
		printf("from classify_input, start_number is  : %s\n",
			mystate->start_number);
		return (mystate->interface->handler_digit(mystate));
	}
	else if (input == ' ')
		return (mystate->interface->handler_space(mystate));
	else if (input == '-')
	{
		if (mystate->nber_dash == 0)
			mystate->addr_first_dash = mystate->mystring;
		return (mystate->interface->handler_dash(mystate));
	}
	else if (input == '\0')
		return (mystate->interface->handler_end(mystate));
	else
		return (mystate->interface->handler_space(mystate));
}

contextState	*initStartState(contextState *ptr_parser)
{
	ptr_parser->interface = &InStartState;
	ptr_parser->name_state = InStart;
	ptr_parser->mystring = NULL;
	ptr_parser->addr_first_dash = NULL;
	ptr_parser->bench_found = NULL;
	ptr_parser->nber_dash = 0;
	ptr_parser->start_number = NULL;
	ptr_parser->option_found = NULL;
}