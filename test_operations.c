/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:30:00 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/02/28 02:52:05 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === CECI EST UN FICHIER TEST POUR VERIFIER SI TOUTES LES OPERATIONS
// MARCHENT== JE NE L'AI PAS ECRIT ON VA REPARLER DE L'IMPLEMENTATION DE PRINTF
// DU PARSING ETC SI ON SE CROISE
#include "push_swap.h"
#include "ft_printf.h"
#include <string.h>


/* Utilisation de macros pour l'outpur*/
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

/* Test counter */
static int	g_tests_passed = 0;
static int	g_tests_failed = 0;

void	print_test_result(const char *test_name, int passed)
{
	if (passed)
	{
		printf("%s[✓]%s %s\n", GREEN, NC, test_name);
		g_tests_passed++;
	}
	else
	{
		printf("%s[✗]%s %s\n", RED, NC, test_name);
		g_tests_failed++;
	}
}

void	test_stack_creation(void)
{
	t_stack	*a;
	t_stack	*b;

	printf("\n%s=== TEST 1: Stack Creation ===%s\n", YELLOW, NC);
	a = new_stack(A);
	b = new_stack(B);
	print_test_result("Create stack A", a != NULL);
	print_test_result("Create stack B", b != NULL);
	print_test_result("Stack A is empty", is_empty_stack(a));
	print_test_result("Stack B is empty", is_empty_stack(b));
	print_test_result("Stack A name is A", a->name == A);
	print_test_result("Stack B name is B", b->name == B);
	clear_stack(&a);
	clear_stack(&b);
	print_test_result("Clear stack A", a == NULL);
	print_test_result("Clear stack B", b == NULL);
}

void	test_node_operations(void)
{
	t_stack	*a;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	printf("\n%s=== TEST 2: Node Operations ===%s\n", YELLOW, NC);
	a = new_stack(A);
	node1 = new_node(42);
	node2 = new_node(21);
	node3 = new_node(84);
	print_test_result("Create node 42", node1 != NULL && node1->value == 42);
	print_test_result("Node is circular", node1->next == node1);
	stack_add_back(a, node1);
	print_test_result("Add node to empty stack", a->length == 1);
	print_test_result("Head equals tail (1 element)", a->head == a->tail);
	stack_add_back(a, node2);
	print_test_result("Add second node", a->length == 2);
	print_test_result("Circular: tail->next == head", a->tail->next == a->head);
	stack_add_front(a, node3);
	print_test_result("Add node at front", a->length == 3);
	print_test_result("New head is 84", a->head->value == 84);
	print_stack(a, "A");
	clear_stack(&a);
}

void	test_pop_operation(void)
{
	t_stack	*a;
	t_node	*popped;

	printf("\n%s=== TEST 3: Pop Operation ===%s\n", YELLOW, NC);
	a = new_stack(A);
	stack_add_back(a, new_node(10));
	stack_add_back(a, new_node(20));
	stack_add_back(a, new_node(30));
	print_stack(a, "A before pop");
	popped = stack_pop_front(a);
	print_test_result("Pop returns correct value", popped->value == 10);
	print_test_result("Stack length decremented", a->length == 2);
	print_test_result("Popped node is isolated", popped->next == NULL);
	free(popped);
	print_stack(a, "A after pop");
	clear_stack(&a);
}

void	test_swap_operation(void)
{
	t_stack		*a;
	t_op_list	*ops;

	printf("\n%s=== TEST 4: Swap Operation ===%s\n", YELLOW, NC);
	a = new_stack(A);
	ops = new_op_list();
	stack_add_back(a, new_node(5));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(7));
	print_stack(a, "A before swap");
	swap(a, ops);
	printf("ops count %zu", ops->count);
	print_test_result("First two elements swapped", a->head->value == 3
		&& a->head->next->value == 5);
	print_stack(a, "A after swap");
	print_test_result("Operation recorded", ops->count == 1);
	clear_stack(&a);
	clear_op_list(&ops);
}

void	test_push_operation(void)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;

	printf("\n%s=== TEST 5: Push Operation ===%s\n", YELLOW, NC);
	a = new_stack(A);
	b = new_stack(B);
	ops = new_op_list();
	stack_add_back(a, new_node(1));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(3));
	print_stack(a, "A before push");
	print_stack(b, "B before push");
	push(a, b, ops);
	print_test_result("Element moved from A to B", a->length == 2
		&& b->length == 1);
	print_test_result("Correct element in B", b->head->value == 1);
	print_stack(a, "A after push");
	print_stack(b, "B after push");
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
}

void	test_rotate_operation(void)
{
	t_stack		*a;
	t_op_list	*ops;

	printf("\n%s=== TEST 6: Rotate Operation ===%s\n", YELLOW, NC);
	a = new_stack(A);
	ops = new_op_list();
	stack_add_back(a, new_node(1));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(3));
	print_stack(a, "A before rotate");
	rotate(a, ops);
	print_test_result("First element moved to end", a->head->value == 2
		&& a->tail->value == 1);
	print_stack(a, "A after rotate");
	print_test_result("Circular structure maintained",
		a->tail->next == a->head);
	clear_stack(&a);
	clear_op_list(&ops);
}

void	test_reverse_rotate_operation(void)
{
	t_stack		*a;
	t_op_list	*ops;

	printf("\n%s=== TEST 7: Reverse Rotate Operation ===%s\n", YELLOW, NC);
	a = new_stack(A);
	ops = new_op_list();
	stack_add_back(a, new_node(1));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(3));
	print_stack(a, "A before reverse rotate");
	reverse_rotate(a, ops);
	print_test_result("Last element moved to front", a->head->value == 3
		&& a->tail->value == 2);
	print_stack(a, "A after reverse rotate");
	print_test_result("Circular structure maintained",
		a->tail->next == a->head);
	clear_stack(&a);
	clear_op_list(&ops);
}

void	test_combined_operations(void)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;

	printf("\n%s=== TEST 8: Combined Operations ===%s\n", YELLOW, NC);
	a = new_stack(A);
	b = new_stack(B);
	ops = new_op_list();
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(1));
	printf("Initial state:\n");
	print_stack(a, "A");
	print_stack(b, "B");
	push(a, b, ops); // A:[2,1]  B:[3]
	push(a, b, ops); // A:[1]    B:[2,3]
	swap(b, ops);    // A:[1]    B:[3,2]
	push(b, a, ops); // A:[3,1]  B:[2]
	printf("\nAfter operations (pb, pb, sb, pa):\n");
	print_stack(a, "A");
	print_stack(b, "B");
	print_test_result("Operations sequence correct", a->head->value == 3
		&& b->head->value == 2); /* ← Corrigé */
	printf("\nOperations recorded:\n");
	print_operations(ops);
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
}

void	test_edge_cases(void)
{
	t_stack		*a;
	t_op_list	*ops;

	printf("\n%s=== TEST 9: Edge Cases ===%s\n", YELLOW, NC);
	a = new_stack(A);
	ops = new_op_list();
	swap(a, ops);
	print_test_result("Swap on empty stack (no crash)", 1);
	rotate(a, ops);
	print_test_result("Rotate on empty stack (no crash)", 1);
	stack_add_back(a, new_node(42));
	swap(a, ops);
	print_test_result("Swap on 1-element stack (no crash)", 1);
	rotate(a, ops);
	print_test_result("Rotate on 1-element stack (no crash)", 1);
	print_test_result("No operations recorded for invalid ops",
		ops->count == 0);
	clear_stack(&a);
	clear_op_list(&ops);
}

void	test_is_node_unique(void)
{
	t_stack	*a;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;

	printf("\n%s=== TEST 10: ARE THERE DUPLICATES ? ===%s\n", YELLOW, NC);
	a = new_stack(A);
	node1 = new_node(-56);
	node2 = new_node(12);
	node3 = new_node(0);
	node4 = new_node(42);
	print_test_result("adding a new node, is it unique?", is_node_unique(a,
			node1));
	print_test_result("adding a new node, is it unique?", is_node_unique(a,
			node2));
	print_test_result("adding a new node, is it unique?", is_node_unique(a,
			node3));
	print_test_result("adding a new node, is it unique?", is_node_unique(a,
			node4));
	print_stack(a, "A");
	clear_stack(&a);
}

void	test_is_in_order(void)
{
	t_stack	*a;

	printf("\n%s=== TEST 11: is_in_order ? ===%s\n", YELLOW, NC);
	a = new_stack(A);
	stack_add_back(a, new_node(-56));
	stack_add_back(a, new_node(12));
	stack_add_back(a, new_node(30));
	stack_add_back(a, new_node(42));
	stack_add_back(a, new_node(2656595));
	print_test_result("is_in_order?", is_in_order(a));
	print_stack(a, "A");
	clear_stack(&a);
}

void	test_compute_disorder(void)
{
	t_stack	*a;
	float	result;

	printf("\n%s=== TEST 12: compute_disorder ===%s\n", YELLOW, NC);
	a = new_stack(A);
	result = compute_disorder(a);
	print_test_result("disorder: empty stack = 0.0", result == 0.0f);
	clear_stack(&a);
	a = new_stack(A);
	stack_add_back(a, new_node(42));
	result = compute_disorder(a);
	print_test_result("disorder: single element = 0.0", result == 0.0f);
	clear_stack(&a);
	a = new_stack(A);
	stack_add_back(a, new_node(1));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(3));
	result = compute_disorder(a);
	print_test_result("disorder: sorted [1,2,3] = 0.0", result == 0.0f);
	clear_stack(&a);
	a = new_stack(A);
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(1));
	result = compute_disorder(a);
	print_test_result("disorder: reversed [3,2,1] = 1.0", result == 1.0f);
	clear_stack(&a);
	a = new_stack(A);
	stack_add_back(a, new_node(4));
	stack_add_back(a, new_node(67));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(87));
	stack_add_back(a, new_node(23));
	result = compute_disorder(a);
	print_test_result("disorder: [4,67,3,87,23] = 40%", result > 0.39f
		&& result < 0.41f);
	clear_stack(&a);
}

void	test_from_ll_to_array(void)
{
	t_stack	*a;
	int		*arr;
	size_t	i;
	t_node	*ptr_node;

	printf("\n%s=== TEST 13: from stack to sorted array ===%s\n", YELLOW, NC);
	i = 0;
	a = new_stack(A);
	stack_add_back(a, new_node(5));
	stack_add_back(a, new_node(6));
	stack_add_back(a, new_node(0));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(4));
	ptr_node = a->head;
	arr = from_ll_to_array(a);
	while (i < a->length)
	{
		printf("stack value :%d array: %d\n ", ptr_node->value, arr[i]);
		print_test_result("compare element by element \n",
			arr[i] == ptr_node->value);
		ptr_node = ptr_node->next;
		i++;
	}
	free(arr);
	clear_stack(&a);
}

void	test_bubble_sort(void)
{
	int		arr[6] = {2, 5, 9, 6, 8, 10};
	size_t	i;

	printf("\n%s=== TEST 14: bubble sorted array ===%s\n", YELLOW, NC);
	i = 0;
	print_array(arr, 6);
	bubble(arr, 6);
	while (i < (6 - 1))
	{
		if (arr[i] > arr[i + 1])
		{
			print_test_result("Not sorted array \n", 0);
			return ;
		}
		i++;
	}
	print_test_result("Sorted array \n", 1);
	print_array(arr, 6);
}

void	test_lis_len(void)
{
	int	mylist[] = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
	int	len_lis;

	len_lis = 0;
	printf("\n%s=== TEST 15: lis array ===%s\n", YELLOW, NC);
	lis(mylist, 10, &len_lis);
	if (len_lis != 5)
	{
		print_test_result("Lis not the right size \n", 0);
		return ;
	}
	print_test_result("Lis has the right size \n", 1);
}

void	test_lis_elements(void)
{
	int	mylist[] = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
	int	lis_expected[] = {3, 4, 6, 7, 9};
	int	len_lis;
	int	*lis_obtained;
	int	i;

	i = 0;
	len_lis = 0;
	printf("\n%s=== TEST 16: lis array ===%s\n", YELLOW, NC);
	lis_obtained = lis(mylist, 10, &len_lis);
	if (len_lis != 5)
	{
		print_test_result("Lis not the right size \n", 0);
		return ;
	}
	while (i < len_lis)
	{
		print_test_result("lis element \n", lis_expected[i] == lis_obtained[i]);
		i++;
	}
}

void	test_add_rank_to_node(void)
{
	t_stack	*a;
	size_t	ranks[] = {3, 4, 0, 1, 2};
	int		*arr;
	size_t	i;
	t_node	*ptr_node;

	printf("\n%s===  TEST 17 sort_array.c: add_rank_node ===%s\n", YELLOW, NC);
	i = 0;
	a = new_stack(A);
	stack_add_back(a, new_node(5));
	stack_add_back(a, new_node(6));
	stack_add_back(a, new_node(0));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(4));
	ptr_node = a->head;
	arr = from_ll_to_array(a);
	bubble(arr, a->length);
	add_rank_node(a);
	while (i < a->length)
	{
		print_test_result("check rank \n", ranks[i] == ptr_node->rank);
		ptr_node = ptr_node->next;
		i++;
	}
	print_stack(a, "A");
	print_rank_stack(a, "A");
	clear_stack(&a);
}

void	test_add_lis_to_nodes(void)
{
	int		lis_expected[] = {3, 4, 6, 7, 9};
	int		len_lis;
	t_stack	*a;
	size_t	i;
	t_node	*ptr_node;
	int		j;

	// int		mylist[] = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
	i = 0;
	len_lis = 0;
	printf("\n%s=== TEST 18 lis.c: add_lis_to_nodes ===%s\n", YELLOW, NC);
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
	ptr_node = a->head;
	add_lis_to_nodes(a);
	while (i < a->length)
	{
		j = 0;
		while (j < len_lis)
		{
			if (lis_expected[j] == ptr_node->value)
				print_test_result("is in lis \n", TRUE == ptr_node->is_lis);
			else
				print_test_result("is in lis \n", FALSE == ptr_node->is_lis);
			j++;
		}
		ptr_node = ptr_node->next;
		i++;
	}
	print_stack(a, "A");
	print_lis_stack(a, "A");
	clear_stack(&a);
}

int	main(void)
{
	printf("%s", BLUE);
	printf("╔════════════════════════════════════════════════╗\n");
	printf("║        PUSH SWAP - Test Suite                  ║\n");
	printf("║        Data Structure Validation               ║\n");
	printf("╚════════════════════════════════════════════════╝\n");
	printf("%s\n", NC);
	/* Call tests functions*/
	// test_stack_creation();
	// test_node_operations();
	// test_pop_operation();
	// test_swap_operation();
	// test_push_operation();
	// test_rotate_operation();
	// test_reverse_rotate_operation();
	// test_combined_operations();
	// test_edge_cases();
	// test_is_node_unique();
	// test_is_in_order();
	// test_compute_disorder();
	// test_from_ll_to_array();
	test_bubble_sort();
	// test_lis_elements();
	// test_add_lis_to_nodes();
	printf("\n%s", BLUE);
	printf("╔════════════════════════════════════════════════╗\n");
	printf("║              Test Results                      ║\n");
	printf("╠════════════════════════════════════════════════╣\n");
	printf("║  %sPassed: %2d%s                                    ║\n", GREEN,
		g_tests_passed, BLUE);
	printf("║  %sFailed: %2d%s ║\n", RED, g_tests_failed, BLUE);
	printf("╚════════════════════════════════════════════════╝\n");
	printf("%s\n", NC);
	return (g_tests_failed == 0 ? 0 : 1);
}
