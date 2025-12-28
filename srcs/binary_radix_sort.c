/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:49:08 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 07:32:46 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_bit_size(int size);
static void	dispatch_to_b(t_stacks *stacks, int bit);
static void	restore_to_a(t_stacks *stacks, int bit, int bit_size);

void	binary_radix_sort(t_stacks *stacks)
{
	int	bit;
	int	bit_size;

	bit_size = get_bit_size(stacks->size_a);
	bit = 0;
	while (bit < bit_size && !ft_issort(stacks->stack_a, stacks->size_a))
	{
		dispatch_to_b(stacks, bit);
		restore_to_a(stacks, bit, bit_size);
		bit++;
	}
}

static int	get_bit_size(int size)
{
	int	bit_size;

	bit_size = 0;
	while (size > 0)
	{
		bit_size++;
		size /= DIVIDE_BY_HALF;
	}
	return (bit_size);
}

static void	dispatch_to_b(t_stacks *stacks, int bit)
{
	int	size;

	size = stacks->size_a;
	while (--size >= 0 && !ft_issort(stacks->stack_a, stacks->size_a))
	{
		if ((stacks->stack_a[STACK_TOP] >> bit) & BIT_MASK)
			rotate_r(stacks, "ra");
		else
			pb(stacks);
	}
}

static void	restore_to_a(t_stacks *stacks, int bit, int bit_size)
{
	int	size;

	size = stacks->size_b;
	while (--size >= 0)
	{
		if (bit < bit_size - 1
			&& ((stacks->stack_b[STACK_TOP] >> (bit + 1))
				& BIT_MASK) == 0)
			rotate_r(stacks, "rb");
		else
			pa(stacks);
	}
}
