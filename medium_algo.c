#include "push_swap.h"

// function to find where is the minimum position of the stack list
// 0 ranked value (index 0). Position is from 1 to len of stack
// pass a ptr to node by adress to get the min node
size_t	find_min_pos(t_stack *stk, t_node **ptr_min)
{
	size_t	i;
	size_t	j;
	t_node	*ptr_node;
	int		min;

	if (stk->length == 0)
		return (0);
	i = 1;
	j = i;
	ptr_node = stk->head;
	*ptr_min = ptr_node;
	min = ptr_node->value;
	while (i <= stk->length)
	{
		if (ptr_node->value < min)
		{
			min = ptr_node->value;
			*ptr_min = ptr_node;
			j = i;
		}
		ptr_node = ptr_node->next;
		i++;
	}
	return (j);
}

int	is_sorted_circular(t_stack *stk)
{
	int		is_sorted;
	t_node	*ptr_min;
	t_node	*head_orig;

	is_sorted = 0;
	head_orig = stk->head;
	ptr_min = stk->head;
	find_min_pos(stk, &ptr_min);
	stk->head = ptr_min;
	is_sorted = is_in_order(stk);
	stk->head = head_orig; // reset the head at the original node
	return (is_sorted);
}

void	algo_lis(void)
{
	printf("============= TEST medium_algo.c: algo_lis ==================\n");
	t_stack *a;
	t_stack *b;
	t_op_list *ops;
	size_t len_a;

	ops = new_op_list();

	// {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
	a = new_stack(A);
	stack_add_back(a, new_node(8));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(4));
	stack_add_back(a, new_node(6));
	stack_add_back(a, new_node(5));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(0));
	stack_add_back(a, new_node(7));
	stack_add_back(a, new_node(9));
	stack_add_back(a, new_node(1));

	if (a->length < 2)
		return ;
	// add lis and rank
	add_lis_to_nodes(a);
	printf("====");
	add_rank_node(a);
	// create stack b
	b = new_stack(B);
	printf("======================================================================\n\n");
	// push all non lis elements to B

	len_a = a->length;
	while (len_a > 0)
	{
		if (a->head->is_lis == 0)
			push(a, b, ops);
		else
			rotate(a, ops);
		print_stack(a, "A");
		print_stack(b, "B");

		len_a--;
	}

	//// print and clean
	printf("=====================================================================\n\n");
	print_stack(a, "A");
	print_stack(b, "B");
	print_lis_stack(a, "A");
	print_lis_stack(b, "B");
	clear_stack(&a);
	clear_stack(&b);
	printf("======================================================================\n\n");
}