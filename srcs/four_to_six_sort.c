/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_to_six_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:49:08 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 07:32:36 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	four_to_six_sort(t_stacks *stacks)
{
	int	half;
	int	i;

	half = stacks->size_a / DIVIDE_BY_HALF;
	i = stacks->size_a;
	while (i > 0)
	{
		if (stacks->stack_a[STACK_TOP] >= half)
			rotate_r(stacks, "ra");
		else
			pb(stacks);
		i--;
	}
	if (stacks->size_a == SORT_THRESHOLD_TWO
		&& stacks->stack_a[STACK_TOP] > stacks->stack_a[STACK_SECOND])
		swap(stacks, "sa");
	if (stacks->size_b == SORT_THRESHOLD_TWO
		&& stacks->stack_b[STACK_TOP] < stacks->stack_b[STACK_SECOND])
		swap(stacks, "sb");
	three_sort(stacks);
	while (stacks->size_b > 0)
		pa(stacks);
}
