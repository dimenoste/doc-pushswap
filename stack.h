/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 03:05:07 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/28 03:06:02 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_stack_name
{
	A,
	B
}	t_stack_name;

typedef struct s_node
{
	long		value;
	int			index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	size_t		length;
	t_stack_name	name;
}	t_stack;

/* stack_init.c */
t_node	*new_node(long value);
t_stack	*new_stack(t_stack_name name);
void	clear_stack(t_stack **stk);

/* stack_helpers.c */
t_bool	is_empty_stack(t_stack *stk);
size_t	stack_length(t_stack *stk);
long	stack_top_peek(t_stack *stk);
t_node	*stack_last(t_stack *stk);
t_node	*stack_first(t_stack *stk);
void	print_stack(t_stack *stack, const char *name);
int		is_node_unique(t_stack *stk, t_node *node);
int		is_in_order(t_stack *stk);

#endif
