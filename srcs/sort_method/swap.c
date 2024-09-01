/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:06:31 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/01 03:25:03 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_pair_stack *pair_stack)
{
	swap(&pair_stack->stack_a.cycle.top);
	write(1, "sa\n", 3);
}

void	sb(t_pair_stack *pair_stack)
{
	swap(&pair_stack->stack_b.cycle.top);
	write(1, "sb\n", 3);
}