/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:38:32 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/13 19:25:48 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_operation
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
	OP_RRR,
}	t_operation;

typedef struct s_op_list
{
	t_operation op;
}t_op_list;
