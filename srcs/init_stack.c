/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:17:00 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/31 21:46:37 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	init_stack(t_pair_stack *pair_stack, int argc);
int			*compress_value(int *value_array, int argc, char **argv);

void	set_stack(t_pair_stack *pair_stack, int argc, char **argv)
{
	int		*value_array;
	int		*order_array;
	t_list	*current;
	int		i;

	init_stack(pair_stack, argc);
	current = pair_stack->stack_a.cycle.top;
	value_array = (int *)malloc(sizeof(int) * argc - 1);
	order_array = compress_value(value_array, argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		current->value = value_array[i];
		current->order = order_array[i];
		current->index = i + 1;
		current = current->next;
		i++;
	}
	free(value_array);
	free(order_array);
}

#include <stdio.h>

static void	init_stack(t_pair_stack *pair_stack, int argc)
{
	int		i;
	t_list	*new_list;
	t_list	*new_list2;

	pair_stack->stack_a.cycle = (t_cycle){NULL, NULL};
	pair_stack->stack_a.count_value = 0;
	pair_stack->stack_b.cycle = (t_cycle){NULL, NULL};
	pair_stack->stack_b.count_value = 0;
	i = 0;
	while (i < argc - 1)
	{
		new_list = (t_list *)malloc(sizeof(t_list));
		if (!new_list)
			error_exit();
		*new_list = (t_list){NULL, NULL, 0, i + 1, 0};
		new_list2 = (t_list *)malloc(sizeof(t_list));
		if (!new_list2)
			error_exit();
		*new_list2 = (t_list){NULL, NULL, 0, i + 1, 0};
		pair_stack->stack_a.count_value++;
		if (!pair_stack->stack_a.cycle.top)
			pair_stack->stack_a.cycle = (t_cycle){new_list, new_list};
		else
		{
			pair_stack->stack_a.cycle.bottom->next = new_list;
			new_list->prev = pair_stack->stack_a.cycle.bottom;
			pair_stack->stack_a.cycle.bottom = new_list;
		}
		i++;
	}
}

int	*compress_value(int *value_array, int argc, char **argv)
{
	int	i;
	int	j;
	int	*order_array;

	i = 0;
	while (i < argc - 1)
	{
		value_array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	order_array = (int *)malloc(sizeof(int) * argc - 1);
	if (!order_array)
		error_exit();
	i = 0;
	while (i < argc - 1)
	{
		order_array[i] = 0;
		j = 0;
		while (j < argc - 1)
		{
			if (value_array[i] > value_array[j])
				order_array[i]++;
			else if (value_array[i] == value_array[j] && i != j)
			{
				free(order_array);
				error_exit();
			}
			j++;
		}
		i++;
	}
	return (order_array);
}
