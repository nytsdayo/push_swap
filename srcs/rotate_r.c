/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:01:23 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 07:08:56 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_up(int *stack, int size);

void	rotate_r(t_stacks *stacks, char *str)
{
	if (ft_strncmp(str, "ra", 2) == 0)
	{
		if (stacks->size_a < 2)
			return ;
		rotate_up(stacks->stack_a, stacks->size_a);
	}
	else
	{
		if (stacks->size_b < 2)
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
	tmp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}
