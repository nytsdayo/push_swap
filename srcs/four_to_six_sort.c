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

	half = stacks->size_a / 2;
	i = stacks->size_a;
	while (i > 0)
	{
		if (stacks->stack_a[0] >= half)
			rotate_r(stacks, "ra");
		else
			pb(stacks);
		i--;
	}
	if (stacks->size_a == 2 && stacks->stack_a[0] > stacks->stack_a[1])
		swap(stacks, "sa");
	if (stacks->size_b == 2 && stacks->stack_b[0] < stacks->stack_b[1])
		swap(stacks, "sb");
	three_sort(stacks);
	while (stacks->size_b > 0)
		pa(stacks);
}
