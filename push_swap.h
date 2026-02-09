/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:38:32 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/02/09 13:50:47 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> // A SUPPRIMER !!!!!!!!!!!!!!!!!!!
# include <stdlib.h>
# include <unistd.h>
/////////////////////////////////////////////////////////////// UTILS FOR PARSING/////////////////////////////////////////////////////////////////////////

typedef struct nber_struct
{
	int						number;
	int						error;
}							t_number;

t_number					ft_patoi(char *s);
int							ft_strcmp_space(char *s1, char *s2);
char						*get_strat_selector(char *s);
char						*get_bench_selector(char *s);
const char					*get_state_name(e_state_name enum_name);
void						classify_input(contextState *mystate);
/////////////////////////////////////////////////////////////// STATE MACHINE FOR PARSING/////////////////////////////////////////////////////////////////////////
// 0) Enum to track names of all different states
typedef enum state_name
{
	InStart,
	InDash,
	InOption,
	InSpace,
	InInvalid,
	InNumber,
	InSuccess
}							e_state_name;

// 1) Context
typedef struct s_interface	stateInterface;
typedef struct s_ctx
{
	stateInterface			*interface;
	e_state_name			name_state;
	char					*mystring;
	char					*addr_first_dash;
	char					*start_number;
	int						nber_digits;
	char					*option_found;
	int						candidate_number;
	char					*bench_found;
	int						nber_dash;
}							contextState;
// 2) State Interface
struct						s_interface
{
	void					(*handler_letter)(contextState *);
	void					(*handler_space)(contextState *);
	void					(*handler_digit)(contextState *);
	void					(*handler_dash)(contextState *);
	void					(*handler_other)(contextState *);
	void					(*handler_end)(contextState *);
};

// delarations of implementations for InStart
void						letterWhenInStart(contextState *currState);
void						spaceWhenInStart(contextState *currState);
void						digitWhenInStart(contextState *currState);
void						dashWhenInStart(contextState *currState);
void						otherWhenInStart(contextState *currState);
void						endWhenInStart(contextState *currState);
// delarations of implementations for InDash
void						letterWhenInDash(contextState *currState);
void						spaceWhenInDash(contextState *currState);
void						digitWhenInDash(contextState *currState);
void						dashWhenInDash(contextState *currState);
void						otherWhenInDash(contextState *currState);
void						endWhenInDash(contextState *currState);
// delarations of implementations for InOption
void						letterWhenInOption(contextState *currState);
void						spaceWhenInOption(contextState *currState);
void						digitWhenInOption(contextState *currState);
void						dashWhenInOption(contextState *currState);
void						otherWhenInOption(contextState *currState);
void						endWhenInOption(contextState *currState);
// delarations of implementations for InSpace
void						letterWhenInSpace(contextState *currState);
void						spaceWhenInSpace(contextState *currState);
void						digitWhenInSpace(contextState *currState);
void						dashWhenInSpace(contextState *currState);
void						otherWhenInSpace(contextState *currState);
void						endWhenInSpace(contextState *currState);
// delarations of implementations for InInvalid(
void						stayInInvalid(contextState *currState);

// delarations of implementations for InNumber
void						letterWhenInNumber(contextState *currState);
void						spaceWhenInNumber(contextState *currState);
void						digitWhenInNumber(contextState *currState);
void						dashWhenInNumber(contextState *currState);
void						otherWhenInNumber(contextState *currState);
void						endWhenInNumber(contextState *currState);

// 3) Transitions
// success on InSuccess
void						toEndSuccess(contextState *currState);

stateInterface				InStartState = {&letterWhenInStart,
					&spaceWhenInStart, &digitWhenInStart, &dashWhenInStart,
					&otherWhenInStart, &endWhenInStart};
stateInterface				InDashState = {&letterWhenInDash, &spaceWhenInDash,
					&digitWhenInDash, &dashWhenInDash, &otherWhenInDash,
					&endWhenInDash};
stateInterface				InOptionState = {&letterWhenInOption,
					&spaceWhenInOption, &digitWhenInOption, &dashWhenInOption,
					&otherWhenInOption, &endWhenInOption};
stateInterface				InSpaceState = {&letterWhenInSpace,
					&spaceWhenInSpace, &digitWhenInSpace, &dashWhenInSpace,
					&otherWhenInSpace, &endWhenInSpace};
stateInterface				InInvalidState = {&stayInInvalid};
stateInterface				InNumberState = {&letterWhenInNumber,
					&spaceWhenInNumber, &digitWhenInNumber, &dashWhenInNumber,
					&otherWhenInNumber, &endWhenInNumber};
stateInterface				InSuccessState = {&toEndSuccess};
/////////////////////////////////////////////////////////////// STRUCTURE OF STACK/////////////////////////////////////////////////////////////////////////

typedef enum e_bool
{
	FALSE,
	TRUE
}							t_bool;
typedef enum e_stack_name
{
	A,
	B
}							t_stack_name;
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
}							t_op_type;

typedef struct s_node
{
	long					value;
	struct s_node			*next;
	struct s_node			*previous;
}							t_node;
typedef struct s_stack
{
	t_node					*head;
	t_node					*tail;
	size_t					length;
	t_stack_name			name;
}							t_stack;

typedef struct s_op_list
{
	t_op_type				*operations;
	size_t					count;
	size_t					capacity;
}							t_op_list;

/// === stack_init.c file ===
t_node						*new_node(long value);
t_stack						*new_stack(t_stack_name name);
void						clear_stack(t_stack **stk);
// === stack_ops.c file ===
void						stack_add_back(t_stack *stk, t_node *node);
void						stack_add_front(t_stack *stk, t_node *node);
t_node						*stack_pop_front(t_stack *from);
//=== operations.c file ===
void						swap(t_stack *stack, t_op_list *ops);
void						swap_both(t_stack *a, t_stack *b, t_op_list *ops);
void						push(t_stack *from, t_stack *to, t_op_list *ops);
//=== operations_rotate.c ===
void						rotate(t_stack *stack, t_op_list *ops);
void						rotate_both(t_stack *a, t_stack *b, t_op_list *ops);
void						reverse_rotate(t_stack *stack, t_op_list *ops);
void						reverse_rotate_both(t_stack *a, t_stack *b,
								t_op_list *ops);
// === operations_list.c file ===
t_op_list					*new_op_list(void);
void						add_operation(t_op_list *list, t_op_type op);
void						print_operations(t_op_list *list);
void						clear_op_list(t_op_list **list);
// stack_helpers.c (utils and fast for debugging during algorithms deployment)
t_bool						is_empty_stack(t_stack *stk);
size_t						stack_length(t_stack *stk);
long						stack_top_peek(t_stack *stk);
t_node						*stack_last(t_stack *stk);
t_node						*stack_first(t_stack *stk);

#endif
