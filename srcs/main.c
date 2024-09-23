/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:44:45 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/24 07:11:17 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a = set_args(argc, argv);
	if (!ft_issort(stacks.stack_a, argc - 1))
	{
		stacks.size_a = argc - 1;
		stacks.stack_b = ft_calloc(argc - 1, sizeof(int));
		stacks.size_b = 0;
		push_swap(stacks);
		free(stacks.stack_b);
	}
	free(stacks.stack_a);
	return (0);
}

int	ft_issort(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
