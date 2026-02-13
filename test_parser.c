/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/13 22:36:25 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_current_state(t_context *ptr_parser)
{
	printf("====== CURR STATE ===============\n");
	printf("current state of string is : %s\n",
		get_state_name(ptr_parser->name_state));
	printf("parser.mystring : %s\n", ptr_parser->mystring);
	printf("option  found is : %s\n", ptr_parser->option_found);
	printf("bench  found is : %s\n", ptr_parser->bench_found);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_context	*ptr_parser;
	t_states	*mystates;

	printf("======= TEST PARSER ============\n");
	i = 1;
	if (argc < 2)
		return (0);
	mystates = init_states();
	while (i <= argc)
	{
		ptr_parser = init_parser(mystates, argv[i]);
		while (1)
		{
			if ((ptr_parser->name_state == InInvalid)
				|| (ptr_parser->name_state == InSuccess))
			{
				printf("======= PREMATURE EXIT : ==========\n");
				// print_current_state(ptr_parser);
				printf("===================================\n");
				return (0);
			}
			printf("parser.mystring : %s\n", ptr_parser->mystring);
			classify_input(ptr_parser, mystates);
			printf("number of dash : %d\n", ptr_parser->nber_dash);
			(ptr_parser->mystring)++;
		}
		printf("======= NEXT WORD: ==========\n");
		i++;
	}
	printf("out of loop current state : %s\n",
		get_state_name(ptr_parser->name_state));
	print_current_state(ptr_parser);
	// if ((parser.option_found) || (parser.name_state == InInvalid))
	// 	printf("error");
	free_mystates(mystates);
	return (0);
}
