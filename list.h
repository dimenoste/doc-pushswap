/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:58:36 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/11 14:07:54 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# endif

typedef struct s_list
{
	long			value;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef enum e_stack_name
{
	a,
	b,
}					t_stack_name;

typedef struct s_stack
{
	t_list			*head;
	t_list			*tail;
	long			length;
	t_stack_name	name;
}					t_stack;
