/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:41:38 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/14 22:00:40 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_context	*init_parser_arg(t_states *mystates, char *s, t_stack *stk)
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
	ptr_parser->stack_A = stk;
	return (ptr_parser);
}
