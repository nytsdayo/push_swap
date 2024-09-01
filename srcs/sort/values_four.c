/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:58:45 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/29 17:50:47 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	case_values_four(t_pair_stack *pair_stack)
{
	int	stack_list[4];

	stack_list[0] = pair_stack->stack_a.cycle.top->order;
	stack_list[1] = pair_stack->stack_a.cycle.top->next->order;
	stack_list[2] = pair_stack->stack_a.cycle.top->next->next->order;
	stack_list[3] = pair_stack->stack_a.cycle.top->next->next->next->order;
	if (stack_list[0] == 1)
	{
		if (stack_list[1] == 2)
		{
			if (stack_list[2] == 4)
			{
				ra(pair_stack);
				ra(pair_stack);
				sa(pair_stack);
				ra(pair_stack);
				ra(pair_stack);
			}
		}
		else if (stack_list[1] == 3)
		{
			if (stack_list[2] == 2)
			{
				rra(pair_stack);
				sa(pair_stack);
				ra(pair_stack);
			}
			else if (stack_list[2] == 4)
			{
				ra(pair_stack);
				sa(pair_stack);
			}
		}
		else if (stack_list[1] == 4)
		{
			if (stack_list[2] == 2)
			{
				sa(pair_stack);
				rra(pair_stack);
			}
			else if (stack_list[2] == 3)
			{
				sa(pair_stack);
				rra(pair_stack);
			}
		}
	}
	else if (stack_list[0] == 2)
	{
		if (stack_list[1] == 1)
		{
			sa(pair_stack);
			if (stack_list[2] == 4)
			{
				ra(pair_stack);
				ra(pair_stack);
				sa(pair_stack);
				ra(pair_stack);
				ra(pair_stack);
			}
		}
		else if (stack_list[1] == 3)
		{
			if (stack_list[2] == 1)
			{
				rra(pair_stack);
				rra(pair_stack);
				sa(pair_stack);
				rra(pair_stack);
			}
			else if (stack_list[2] == 4)
				ra(pair_stack);
			if (stack_list[2] == 1)
			{
			}
		}
		else if (stack_list[0] == 3)
		{
			if (stack_list[1] == 1)
			{
				if (stack_list[2] == 2)
				{
					ra(pair_stack);
					sa(pair_stack);
					ra(pair_stack);
					ra(pair_stack);
				}
			}
		}
	}
}
