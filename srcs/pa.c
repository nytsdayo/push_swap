/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:01:23 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 07:09:42 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	shift_up(int *stack, int size);
static void	shift_down(int *stack, int size);

void	pa(t_stacks *stacks)
{
	if (stacks->size_b < 1)
		return ;
	shift_up(stacks->stack_a, stacks->size_a);
	stacks->stack_a[0] = stacks->stack_b[0];
	shift_down(stacks->stack_b, stacks->size_b);
	stacks->size_a++;
	stacks->size_b--;
	ft_putendl_fd("pa", 1);
}

static void	shift_up(int *stack, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
}

static void	shift_down(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}
