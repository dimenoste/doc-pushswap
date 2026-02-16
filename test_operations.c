/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:30:00 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/02/15 19:17:56 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === CECI EST UN FICHIER TEST POUR VERIFIER SI TOUTES LES OPERATIONS
// MARCHENT== JE NE L'AI PAS ECRIT ON VA REPARLER DE L'IMPLEMENTATION DE PRINTF
// DU PARSING ETC SI ON SE CROISE
#include "push_swap.h"
#include <stdio.h>
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

	printf("\n%s=== TEST 10: Node Operations ===%s\n", YELLOW, NC);
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

int	main(void)
{
	printf("%s", BLUE);
	printf("╔════════════════════════════════════════════════╗\n");
	printf("║        PUSH SWAP - Test Suite                  ║\n");
	printf("║        Data Structure Validation               ║\n");
	printf("╚════════════════════════════════════════════════╝\n");
	printf("%s\n", NC);
	test_stack_creation();
	test_node_operations();
	test_pop_operation();
	test_swap_operation();
	test_push_operation();
	test_rotate_operation();
	test_reverse_rotate_operation();
	test_combined_operations();
	test_edge_cases();
	test_is_node_unique();
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
