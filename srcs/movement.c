/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:01:23 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/24 07:41:37 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stacks *stacks, char *str)
{
	int	tmp;

	if (stacks->size_a < 2)
		return ;
	if (ft_strncmp(str, "sa", 2) == 0)
	{
		tmp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = tmp;
	}
	else
	{
		tmp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = tmp;
	}
	ft_putendl_fd(str, 1);
}

void	rotate_rr(t_stacks *stacks, char *str)
{
	int	i;
	int	tmp;

	if (ft_strncmp(str, "rra", 3) == 0)
	{
		if (stacks->size_a < 2)
			return ;
		i = stacks->size_a;
		tmp = stacks->stack_a[i - 1];
		while (--i > 0)
			stacks->stack_a[i] = stacks->stack_a[i - 1];
		stacks->stack_a[0] = tmp;
	}
	else
	{
		if (stacks->size_b < 2)
			return ;
		i = stacks->size_b;
		tmp = stacks->stack_b[i - 1];
		while (--i > 0)
			stacks->stack_b[i] = stacks->stack_b[i - 1];
		stacks->stack_b[0] = tmp;
	}
	ft_putendl_fd(str, 1);
}

void	rotate_r(t_stacks *stacks, char *str)
{
	int	i;
	int	tmp;

	if (ft_strncmp(str, "ra", 2) == 0)
	{
		if (stacks->size_a < 2)
			return ;
		i = -1;
		tmp = stacks->stack_a[0];
		while (++i < stacks->size_a - 1)
			stacks->stack_a[i] = stacks->stack_a[i + 1];
		stacks->stack_a[i] = tmp;
	}
	else
	{
		if (stacks->size_b < 2)
			return ;
		i = -1;
		tmp = stacks->stack_b[0];
		while (++i < stacks->size_b - 1)
			stacks->stack_b[i] = stacks->stack_b[i + 1];
		stacks->stack_b[i] = tmp;
	}
	ft_putendl_fd(str, 1);
}

void	pa(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b < 1)
		return ;
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_a++;
	stacks->size_b--;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a < 1)
		return ;
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_a--;
	stacks->size_b++;
	ft_putendl_fd("pb", 1);
}
