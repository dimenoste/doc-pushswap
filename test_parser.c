/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/14 20:08:38 by mberraho         ###   ########.fr       */
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

int	parse_args(int argc, char *argv[], t_stack *stk)
{
	t_context	*ptr_parser;
	t_states	*mystates;
	int			i;

	i = 1;
	mystates = init_states();
	while (i < argc)
	{
		ptr_parser = init_parser(mystates, argv[i], stk);
		while (1)
		{
			classify_input(ptr_parser, mystates);
			if ((ptr_parser->name_state == InInvalid))
			{
				clear_stack(&stk);
				return (0);
			}
			else if ((ptr_parser->name_state == InSuccess))
				break ;
			print_current_state(ptr_parser);
			(ptr_parser->mystring)++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stk;

	stk = new_stack(A);
	if (argc < 2 || (parse_args(argc, argv, stk) == 0))
		return (0);
	clear_stack(&stk);
	return (0);
}
