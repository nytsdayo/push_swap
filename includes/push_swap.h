/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:41:57 by rnakatan          #+#    #+#             */
/*   Updated: 2025/12/27 08:33:47 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_loop
{
	int			i;
	int			j;
}				t_loop;

typedef struct s_check_arg
{
	t_loop		loop;
	long long	res;
	int			sign;
}				t_check_arg;

typedef struct s_stacks
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stacks;

int				*set_args(int argc, char **argv);
void			push_swap(t_stacks stacks);
void			three_sort(t_stacks *stacks);
void			four_to_six_sort(t_stacks *stacks);
void			binary_radix_sort(t_stacks *stacks);
int				ft_issort(int *array, int size);

void			swap(t_stacks *stacks, char *str);
void			rotate_r(t_stacks *stacks, char *str);
void			rotate_rr(t_stacks *stacks, char *str);
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);

#endif
