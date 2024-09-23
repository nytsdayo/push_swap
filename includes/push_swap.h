/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:41:57 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/24 07:41:59 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}		t_stacks;

int		*set_args(int argc, char **argv);
int		ft_issort(int *array, int size);
void	push_swap(t_stacks stacks);

void	swap(t_stacks *stacks, char *str);
void	rotate_r(t_stacks *stacks, char *str);
void	rotate_rr(t_stacks *stacks, char *str);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

#endif