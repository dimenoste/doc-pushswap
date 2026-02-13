/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:41:38 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/13 21:17:02 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	classify_input(t_context *curr_state, t_states *mystates)
{
	char	input;

	input = *(curr_state->mystring);
	printf("from classify_input, input is : %c\n", input);
	if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		return (curr_state->interface->handler_letter(curr_state, mystates));
	else if (input >= '0' && input <= '9')
	{
		printf("from classify_input, inpur is a number : %c\n", input);
		if (curr_state->nber_digits == 0)
			curr_state->start_number = curr_state->mystring;
		printf("from classify_input, start_number is  : %s\n",
			curr_state->start_number);
		return (curr_state->interface->handler_digit(curr_state, mystates));
	}
	else if (input == ' ')
		return (curr_state->interface->handler_space(curr_state, mystates));
	else if (input == '-')
	{
		if (curr_state->nber_dash == 0)
			curr_state->addr_first_dash = curr_state->mystring;
		return (curr_state->interface->handler_dash(curr_state, mystates));
	}
	else if (input == '\0')
		return (curr_state->interface->handler_end(curr_state, mystates));
	else
		return (curr_state->interface->handler_space(curr_state, mystates));
}

t_context	*init_parser(t_states *mystates, char *s)
{
	t_context	*ptr_parser;

	ptr_parser = malloc(sizeof(t_context));
	if (!ptr_parser)
	{
		return (NULL);
	}
	ptr_parser->interface = mystates->ptr_in_start_state;
	ptr_parser->name_state = InStart;
	ptr_parser->mystring = s;
	ptr_parser->addr_first_dash = NULL;
	ptr_parser->bench_found = NULL;
	ptr_parser->nber_dash = 0;
	ptr_parser->start_number = NULL;
	ptr_parser->option_found = NULL;
	return (ptr_parser);
}
