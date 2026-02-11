/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 22:40:24 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_current_state(t_context_state *ptr_parser)
{
	printf("====== FINAL DATA IN STATE ===============\n");
	printf("current state of string is : %s\n",
		get_state_name(ptr_parser->name_state));
	printf("option  found is : %s\n", ptr_parser->option_found);
	printf("bench  found is : %s\n", ptr_parser->bench_found);
}

int	main(int argc, char *argv[])
{
	int						i;
	t_context_state			parser;
	t_implement_handlers	mystates;

	i = 1;
	if (argc < 2)
		return (0);
	toin_start_state(&parser, &mystates);
	printf("word to parse : %s\n", parser.addr_first_dash);
	while (i <= argc)
	{
		parser.mystring = argv[i];
		while (*parser.mystring)
		{
			if ((parser.name_state == InInvalid)
				|| (parser.name_state == InSuccess))
			{
				printf("premature exit : %s\n",
					get_state_name(parser.name_state));
				return (0);
			}
			printf("parser.mystring : %s\n", parser.mystring);
			classify_input(&parser, &mystates);
			printf("number of dash : %d\n", parser.nber_dash);
			parser.mystring++;
		}
		i++;
	}
	printf("out of loop current state : %s\n",
		get_state_name(parser.name_state));
	print_current_state(&parser);
	// if ((parser.option_found) || (parser.name_state == InInvalid))
	// 	printf("error");
	return (0);
}
