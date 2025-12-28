/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:01:23 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 07:08:24 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_stack(int *stack);

void	swap(t_stacks *stacks, char *str)
{
	if (stacks->size_a < 2)
		return ;
	if (ft_strncmp(str, "sa", 2) == 0)
		swap_stack(stacks->stack_a);
	else
		swap_stack(stacks->stack_b);
	ft_putendl_fd(str, 1);
}

static void	swap_stack(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}
