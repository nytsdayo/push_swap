/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:08:32 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/30 21:28:47 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef struct s_loop_index
{
	int		i;
	int		j;
}			t_loop_index;

static int	in_range_integer(const char *str);

void	arg_check(int argc, char **argv)
{
	t_loop_index	loop_index;

	loop_index.i = 1;
	if (argc < 3)
		exit(1);
	while (loop_index.i < argc)
	{
		if (!in_range_integer(argv[loop_index.i]))
			error_exit();
		loop_index.j = 0;
		if (ft_issimbol(argv[loop_index.i][loop_index.j]))
			loop_index.j++;
		while (argv[loop_index.i][loop_index.j])
		{
			if (!ft_isdigit(argv[loop_index.i][loop_index.j])
				&& !ft_isspace(argv[loop_index.i][loop_index.j]))
				error_exit();
			loop_index.j++;
		}
		loop_index.i++;
	}
}

static int	in_range_integer(const char *str)
{
	int		i;
	char	min_int[13] = "-2147483648";

	i = 0;
	if (str == min_int)
		return (1);
	if (str[0] == '-')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	if (ft_strlen(str + i) == 10 && ft_strcmp(str + i, "2147483647") > 0)
		return (0);
	return (1);
}
