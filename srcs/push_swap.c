/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:49:08 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/24 06:55:31 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	three_sort(t_stacks *stacks)
{
	if (stacks->size_a == 3)
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
	if (stacks->size_b == 3)
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
}

static void	four_to_six_sort(t_stacks *stacks)
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

static int	get_bit_size(int size)
{
	int	bit_size;

	bit_size = 0;
	while (size > 0)
	{
		bit_size++;
		size /= 2;
	}
	return (bit_size);
}

static void	bainary_radix_sort(t_stacks *stacks)
{
	int	i;
	int	bit_size;
	int	size;

	bit_size = get_bit_size(stacks->size_a);
	i = 0;
	while (i < bit_size && !ft_issort(stacks->stack_a, stacks->size_a))
	{
		size = stacks->size_a;
		while (size > 0 && stacks->size_a > 0 && !ft_issort(stacks->stack_a,
				stacks->size_a))
		{
			if ((stacks->stack_a[0] >> i) & 1)
				rotate_r(stacks, "ra");
			else
				pb(stacks);
			size--;
		}
		while (stacks->size_b > 0)
			pa(stacks);
		i++;
	}
}

void	push_swap(t_stacks stacks)
{
	if (stacks.size_a == 2)
	{
		if (stacks.stack_a[0] > stacks.stack_a[1])
			swap(&stacks, "sa");
	}
	else if (stacks.size_a == 3)
		three_sort(&stacks);
	else if (stacks.size_a <= 6)
		four_to_six_sort(&stacks);
	else
		bainary_radix_sort(&stacks);
}
