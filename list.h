/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:58:36 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/11 14:59:06 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

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

#endif
