/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:58:36 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/13 17:52:48 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <unistd.h>
#include "bool.h"

typedef enum e_stack_name
{
	a,
	b,
}					t_stack_name;

typedef struct s_list
{
	long			value;
	int index;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_stack
{
	t_list			*head;
	t_list			*tail;
	long			length;
	t_stack_name	name;
}					t_stack;

// Prototypes
t_list	*new_list(void);
t_bool	is_empty(t_list *lst);
t_bool	is_empty_node(t_stack *stk);
long	stack_length(t_stack *stk);
t_list	*stack_last(t_stack *stk);
t_list *stack_first(t_stack *stk);



#endif
