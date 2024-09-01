/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:40:12 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/29 14:40:49 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	first = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_pair_stack *pair_stack)
{
	rotate(&pair_stack->stack_a.cycle.top);
	write(1, "ra\n", 3);
}

void	rb(t_pair_stack *pair_stack)
{
	rotate(&pair_stack->stack_b.cycle.top);
	write(1, "rb\n", 3);
}

void	rra(t_pair_stack *pair_stack)
{
	t_list	*last;
	t_list	*first;

	if (!pair_stack->stack_a.cycle.top || !pair_stack->stack_a.cycle.top->next)
		return ;
	last = pair_stack->stack_a.cycle.top;
	first = pair_stack->stack_a.cycle.top;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	first->next = NULL;
	last->next = pair_stack->stack_a.cycle.top;
	pair_stack->stack_a.cycle.top = last;
	write(1, "rra\n", 4);
}

void	rrb(t_pair_stack *pair_stack)
{
	t_list	*last;
	t_list	*first;

	if (!pair_stack->stack_b.cycle.top || !pair_stack->stack_b.cycle.top->next)
		return ;
	last = pair_stack->stack_b.cycle.top;
	first = pair_stack->stack_b.cycle.top;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	first->next = NULL;
	last->next = pair_stack->stack_b.cycle.top;
	pair_stack->stack_b.cycle.top = last;
	write(1, "rrb\n", 4);
}
