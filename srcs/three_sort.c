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
	if (stacks->size_a == SORT_THRESHOLD_THREE)
		sort_three_stack_a(stacks);
	if (stacks->size_b == SORT_THRESHOLD_THREE)
		sort_three_stack_b(stacks);
}

static void	sort_three_stack_a(t_stacks *stacks)
{
	if (stacks->stack_a[STACK_THIRD] != stacks->size_b + SORT_THRESHOLD_TWO)
	{
		if (stacks->stack_a[STACK_SECOND]
			== stacks->size_b + SORT_THRESHOLD_TWO)
			rotate_rr(stacks, "rra");
		else
			rotate_r(stacks, "ra");
	}
	if (stacks->stack_a[STACK_TOP] > stacks->stack_a[STACK_SECOND])
		swap(stacks, "sa");
}

static void	sort_three_stack_b(t_stacks *stacks)
{
	if (stacks->stack_b[STACK_THIRD] != STACK_TOP)
	{
		if (stacks->stack_b[STACK_SECOND] == STACK_TOP)
			rotate_rr(stacks, "rrb");
		else
			rotate_r(stacks, "rb");
	}
	if (stacks->stack_b[STACK_TOP] < stacks->stack_b[STACK_SECOND])
		swap(stacks, "sb");
}
