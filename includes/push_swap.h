/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:41:57 by rnakatan          #+#    #+#             */
/*   Updated: 2024/10/30 19:41:17 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stacks;

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

int				*set_args(int argc, char **argv);
void			push_swap(t_stacks stacks);
int				ft_issort(int *array, int size);

void			swap(t_stacks *stacks, char *str);
void			rotate_r(t_stacks *stacks, char *str);
void			rotate_rr(t_stacks *stacks, char *str);
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);

#endif