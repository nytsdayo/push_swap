/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:54:18 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/01 16:03:24 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void		push_swap(t_pair_stack *pair_stack);
static int	is_sorted(t_pair_stack *pair_stack);

int	main(int argc, char **argv)
{
	t_pair_stack	pair_stack;

	arg_check(argc, argv);
	set_stack(&pair_stack, argc, argv);
	push_swap(&pair_stack);
	return (0);
}

void	push_swap(t_pair_stack *pair_stack)
{
	int		i;
	t_list	*serach;
	int		a_count;
	int		current_index;

	if (is_sorted(pair_stack))
	{
		return ;
	}
	i = 0;
	a_count = pair_stack->stack_a.count_value;
	while (i < a_count)
	{
		serach = pair_stack->stack_a.cycle.top;
		current_index = serach->index;
		(void)current_index;
		while (serach->order != i)
			serach = serach->next;
		// if (current_index - serach->index < pair_stack->stack_a.count_value
		/// 2)
		// 	while (pair_stack->stack_a.cycle.top->order != i)
		// 		ra(pair_stack);
		// else
		// 	while (pair_stack->stack_a.cycle.top->order != i)
		// 		rra(pair_stack);
		while (pair_stack->stack_a.cycle.top->order != i)
			ra(pair_stack);
		pb(pair_stack);
		i++;
	}
	i = 0;
	while (i < pair_stack->stack_b.count_value)
		pa(pair_stack);
	// i = 0;
	// while (i < pair_stack->stack_a.count_value)
	// {
	// 	pair_stack->stack_a.cycle.top = pair_stack->stack_a.cycle.top->next;
	// 	printf("order: %d\n", pair_stack->stack_a.cycle.top->order);
	// 	i++;
	// }
}
// void	push_swap(t_pair_stack *pair_stack)
// {
// 	int	count;

// 	if (is_sorted(pair_stack))
// 		return ;
// 	count = pair_stack->stack_a.count_value;
// 	if (count == 2)
// 	{
// 		if (pair_stack->stack_a.cycle.top->order == 2)
// 			sa(pair_stack);
// 	}
// 	else if (count == 3)
// 		case_values_three(pair_stack);
// 	else if (count == 4)
// 		case_values_four(pair_stack);
// 	for (int i = 0; i < pair_stack->stack_a.count_value; i++)
// 	{
// 		printf("order: %d\n", pair_stack->stack_a.cycle.top->order);
// 		pair_stack->stack_a.cycle.top = pair_stack->stack_a.cycle.top->next;
// 	}
// }

static int	is_sorted(t_pair_stack *pair_stack)
{
	t_list	*current;
	int		count;

	current = pair_stack->stack_a.cycle.top;
	count = pair_stack->stack_a.count_value;
	while (count > 0)
	{
		if (current->order > current->next->order)
			return (0);
		count--;
		if (current)
			current = current->next;
	}
	printf("success\n");
	return (1);
}
