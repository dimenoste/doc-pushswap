/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:38:32 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/03 18:43:35 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;
typedef enum e_stack_name
{
	A,
	B
}					t_stack_name;
typedef enum e_op_type
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}					t_op_type;

typedef struct s_node
{
	long			value;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;
typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	size_t			length;
	t_stack_name	name;
}					t_stack;

typedef struct s_op_list
{
	t_op_type		*operations;
	size_t			count;
	size_t			capacity;
}					t_op_list;

/// === stack_init.c file ===
t_node		*new_node(long value);
t_stack		*new_stack(t_stack_name name);
void		clear_stack(t_stack **stk);
// === stack_ops.c file ===
void		stack_add_back(t_stack *stk, t_node *node);
void		stack_add_front(t_stack *stk, t_node *node);
t_node		*stack_pop_front(t_stack *from);
//=== operations.c file ===
void		swap(t_stack *stack, t_op_list *ops);
void		swap_both(t_stack *a, t_stack *b, t_op_list *ops);
void		push(t_stack *from, t_stack *to, t_op_list *ops);
//=== operations_rotate.c ===
void		rotate(t_stack *stack, t_op_list *ops);
void		rotate_both(t_stack *a, t_stack *b, t_op_list *ops);
void		reverse_rotate(t_stack *stack, t_op_list *ops);
void		reverse_rotate_both(t_stack *a, t_stack *b, t_op_list *ops);
// === operations_list.c file ===
t_op_list	*new_op_list(void);
void		add_operation(t_op_list *list, t_op_type op);
void		print_operations(t_op_list *list);
void		clear_op_list(t_op_list **list);
//stack_helpers.c (utils and fast for debugging during algorithms deployment)
t_bool		is_empty_stack(t_stack *stk);
size_t		stack_length(t_stack *stk);
long		stack_top_peek(t_stack *stk);
t_node		*stack_last(t_stack *stk);
t_node		*stack_first(t_stack *stk);

#endif
