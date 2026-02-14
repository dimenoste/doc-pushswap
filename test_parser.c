/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/14 22:48:15 by mberraho         ###   ########.fr       */
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
	print_stack(output->stack_A, "stack from parsing");
}

t_output_parsing	init_output_parser(void)
{
	t_output_parsing	output;
	t_stack				*stk;

	stk = new_stack(A);
	output.name_state = InInvalid;
	output.option_found = NULL;
	output.bench_found = NULL;
	output.stack_A = stk;
	return (output);
}

void	update_output_parser(t_context *ptr_parser, t_output_parsing *output)
{
	output->name_state = ptr_parser->name_state;
	if (!output->option_found && ptr_parser->option_found)
		output->option_found = ptr_parser->option_found;
	if (!output->bench_found && ptr_parser->bench_found)
		output->bench_found = ptr_parser->bench_found;
	output->stack_A = ptr_parser->stack_A;
}

int	parse_args(int argc, char *argv[])
{
	t_context			*ptr_parser;
	t_states			*mystates;
	int					i;
	t_output_parsing	output;

	output = init_output_parser();
	i = 1;
	mystates = init_states();
	while (i < argc)
	{
		ptr_parser = init_parser_arg(mystates, argv[i], output.stack_A);
		while (1)
		{
			classify_input(ptr_parser, mystates);
			update_output_parser(ptr_parser, &output);
			print_current_state(&output);
			if ((output.name_state == InInvalid))
			{
				clear_stack(&output.stack_A);
				return (0);
			}
			else if ((ptr_parser->name_state == InSuccess))
				break ;
			(ptr_parser->mystring)++;
		};
		i++;
	}
	return (1);
}

// validate_parser()

int	main(int argc, char *argv[])
{
	if (argc < 2 || (parse_args(argc, argv) == 0))
		return (0);
	return (0);
}
