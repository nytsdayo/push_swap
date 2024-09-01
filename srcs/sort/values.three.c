/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:47:20 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/29 16:53:57 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	case_values_three(t_pair_stack *pair_stack)
{
	int	stack_list[3];

	stack_list[0] = pair_stack->stack_a.cycle.top->order;
	stack_list[1] = pair_stack->stack_a.cycle.top->next->order;
	stack_list[2] = pair_stack->stack_a.cycle.top->next->next->order;
	if (stack_list[0] == 3)
	{
		if (stack_list[1] == 2)
			ra(pair_stack);
		else
			sa(pair_stack);
		ra(pair_stack);
	}
	if (stack_list[0] == 2)
	{
		if (stack_list[1] == 3)
			ra(pair_stack);
		else
			sa(pair_stack);
	}
	if (stack_list[0] == 1 && stack_list[1] == 3)
	{
		sa(pair_stack);
		ra(pair_stack);
	}
}
