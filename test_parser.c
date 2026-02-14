/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/14 17:59:53 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_current_state(t_context *ptr_parser)
{
	printf("====== CURR STATE ===============\n");
	printf("current state of string is : %s\n",
		get_state_name(ptr_parser->name_state));
	if (ptr_parser->mystring)
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
	// need to free the mallocs
	while (i < argc)
	{
		ptr_parser = init_parser(mystates, argv[i]);
		while (1)
		{
			classify_input(ptr_parser, mystates);
			if ((ptr_parser->name_state == InInvalid))
			{
				printf("INVALID STATE REACHED AT END FOR ARG %s\n", argv[i]);
				return (0);
			}
			else if ((ptr_parser->name_state == InSuccess))
			{
				printf("SUCCESS STATE REACHED AT END FOR ARG %s\n", argv[i]);
				break ;
			}
			print_current_state(ptr_parser);
			(ptr_parser->mystring)++;
		}
		i++;
	}
	// printf("out of loop current state : %s\n",
	// 	get_state_name(ptr_parser->name_state));
	// print_current_state(ptr_parser);
	// // if ((parser.option_found) || (parser.name_state == InInvalid))
	// // 	printf("error");
	// free_mystates(mystates);
	// // need to free parser mallocs
	return (0);
}
