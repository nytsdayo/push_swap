/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:01:23 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 07:09:24 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_down(int *stack, int size);

void	rotate_rr(t_stacks *stacks, char *str)
{
	if (ft_strncmp(str, "rra", 3) == 0)
	{
		if (stacks->size_a < 2)
			return ;
		rotate_down(stacks->stack_a, stacks->size_a);
	}
	else
	{
		if (stacks->size_b < 2)
			return ;
		rotate_down(stacks->stack_b, stacks->size_b);
	}
	ft_putendl_fd(str, 1);
}

static void	rotate_down(int *stack, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = stack[i - 1];
	while (--i > 0)
		stack[i] = stack[i - 1];
	stack[0] = tmp;
}
