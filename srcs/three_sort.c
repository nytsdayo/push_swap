/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:49:08 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 07:32:24 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_stack_a(t_stacks *stacks);
static void	sort_three_stack_b(t_stacks *stacks);

void	three_sort(t_stacks *stacks)
{
	if (stacks->size_a == 3)
		sort_three_stack_a(stacks);
	if (stacks->size_b == 3)
		sort_three_stack_b(stacks);
}

static void	sort_three_stack_a(t_stacks *stacks)
{
	if (stacks->stack_a[2] != stacks->size_b + 2)
	{
		if (stacks->stack_a[1] == stacks->size_b + 2)
			rotate_rr(stacks, "rra");
		else
			rotate_r(stacks, "ra");
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap(stacks, "sa");
}

static void	sort_three_stack_b(t_stacks *stacks)
{
	if (stacks->stack_b[2] != 0)
	{
		if (stacks->stack_b[1] == 0)
			rotate_rr(stacks, "rrb");
		else
			rotate_r(stacks, "rb");
	}
	if (stacks->stack_b[0] < stacks->stack_b[1])
		swap(stacks, "sb");
}
