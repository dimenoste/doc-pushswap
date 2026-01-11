/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:58:36 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/11 16:36:25 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE,
}					t_bool;

typedef enum e_stack_name
{
	a,
	b,
}					t_stack_name;

typedef struct s_list
{
	long			value;
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
t_list				*new_lst(void);
t_bool				is_empty(t_list *lst);
t_bool				is_empty_stack(t_stack *stk);
long				stack_length(t_stack *stk);
long				stack_first(t_stack *stk);
long				stack_last(t_stack *stk);
void				push(t_stack *from, t_stack *to);
void				swap(t_stack *sw);
void				rotate(t_stack *r);

#endif
