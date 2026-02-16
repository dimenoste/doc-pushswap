/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 19:04:55 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_current_state(t_output_parsing *output)
{
	printf("====== CURR STATE ===============\n");
	printf("current state of string is : %s\n",
		get_state_name(output->name_state));
	if (output->option_found)
		printf("option  found is : %s\n", output->option_found);
	else
		printf("option  not found \n");
	if (output->bench_found)
		printf("bench  found is : %s\n", output->bench_found);
	else
		printf("bench  not found \n");
	print_stack(output->stack_a, "stack from parsing");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = run_parser(argc, argv);
	// print_stack(stack_a, "AFTER parsing");
	clear_stack(&stack_a);
	return (0);
}
