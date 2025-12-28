/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:44:45 by rnakatan          #+#    #+#             */
/*   Updated: 2024/10/31 03:19:33 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	put_error_and_exit(void);

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a = set_args(argc, argv);
	if (!stacks.stack_a)
		put_error_and_exit();
	if (!ft_issort(stacks.stack_a, argc - 1))
	{
		stacks.size_a = argc - 1;
		stacks.stack_b = ft_calloc(argc - 1, sizeof(int));
		if (!stacks.stack_b)
			put_error_and_exit();
		stacks.size_b = 0;
		push_swap(stacks);
		free(stacks.stack_b);
	}
	free(stacks.stack_a);
	return (0);
}

static void	put_error_and_exit(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(1);
}
