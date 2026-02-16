/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/15 19:39:24 by mberraho         ###   ########.fr       */
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

int	validate_args(int argc, char *argv[], t_output_parsing *output)
{
	t_context	*ptr_parser;
	t_states	*mystates;
	int			i;

	i = 1;
	mystates = init_states();
	while (i < argc)
	{
		ptr_parser = init_parser_arg(mystates, argv[i], output->stack_A);
		while (1)
		{
			classify_input(ptr_parser, mystates);
			update_output_parser(ptr_parser, output);
			if ((output->name_state == InInvalid))
			{
				clear_stack(&(output->stack_A));
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

void	run_parser(int argc, char *argv[])
{
	t_output_parsing	output;
	int					is_args_valid;

	is_args_valid = 0;
	if (argc < 2 || is_args_valid)
		return ;
	output = init_output_parser();
	is_args_valid = validate_args(argc, argv, &output);
	print_current_state(&output);
	if (output.name_state == InInvalid)
	{
		write(2, "Error\n", 7);
		return ;
	}
	if (is_empty_stack(output.stack_A))
	{
		return ;
	}
}

int	main(int argc, char *argv[])
{
	run_parser(argc, argv);
	return (0);
}
