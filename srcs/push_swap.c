/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:49:08 by rnakatan          #+#    #+#             */
/*   Updated: 2024/10/31 03:23:48 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stacks stacks)
{
	if (stacks.size_a == SORT_THRESHOLD_TWO)
	{
		if (stacks.stack_a[STACK_TOP] > stacks.stack_a[STACK_SECOND])
			swap(&stacks, "sa");
	}
	else if (stacks.size_a == SORT_THRESHOLD_THREE)
		three_sort(&stacks);
	else if (stacks.size_a <= SORT_THRESHOLD_SIX)
		four_to_six_sort(&stacks);
	else
		binary_radix_sort(&stacks);
}
