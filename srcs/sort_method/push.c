/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:53:49 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/01 16:20:53 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}
{
	t_list *tmp;

	if (!pair_stack->stack_a.cycle.top)
		return ;
	tmp = pair_stack->stack_a.cycle.top;
	pair_stack->stack_a.cycle.top = pair_stack->stack_a.cycle.top->next;
	tmp->next = pair_stack->stack_b.cycle.top;
	pair_stack->stack_b.cycle.top = tmp;
}

void	pa(t_pair_stack *pair_stack)
{
	push(&pair_stack);
	pair_stack->stack_a.count_value++;
	pair_stack->stack_b.count_value--;
	write(1, "pa\n", 3);
}

void	pb(t_pair_stack *pair_stack)
{
	push(&pair_stack->stack_a.cycle.top, &pair_stack->stack_b.cycle.top);
	pair_stack->stack_a.count_value--;
	pair_stack->stack_b.count_value++;
	write(1, "pb\n", 3);
}
