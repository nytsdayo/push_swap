/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:01:23 by rnakatan          #+#    #+#             */
/*   Updated: 2025/12/28 17:57:48 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_up(int *stack, int size);

void	rotate_r(t_stacks *stacks, char *str)
{
	if (ft_strncmp(str, "ra", 2) == 0)
	{
		if (stacks->size_a < MIN_ROTATE_SIZE)
			return ;
		rotate_up(stacks->stack_a, stacks->size_a);
	}
	else
	{
		if (stacks->size_b < MIN_ROTATE_SIZE)
			return ;
		rotate_up(stacks->stack_b, stacks->size_b);
	}
	ft_putendl_fd(str, 1);
}

static void	rotate_up(int *stack, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[STACK_TOP];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}
