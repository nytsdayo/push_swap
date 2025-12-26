/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:41:57 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/06 02:03:22 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

// struct
typedef struct s_loop
{
	int			i;
	int			j;
}				t_loop;
typedef struct s_check_arg
{
	t_loop		loop;
	long long	res;
}				t_check_arg;
typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}		t_stacks;

// function
int		*set_args(int argc, char **argv);
int		ph_issort(const int *array, const int size);
void	push_swap(t_stacks stacks);

void	swap(t_stacks *stacks, char *str);
void	rotate_r(t_stacks *stacks, char *str);
void	rotate_rr(t_stacks *stacks, char *str);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

#endif