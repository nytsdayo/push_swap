/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:48:33 by rnakatan          #+#    #+#             */
/*   Updated: 2024/09/24 07:36:54 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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

static int		ft_isvalid_args(char **argv);
static int		*check_duplicates_and_compression(int *array, int size);
static void		invalid_case_exit(char *str);

int	*set_args(int argc, char **argv)
{
	int		*array;
	int		*compression_array;
	t_loop	loop;

	if (argc < 3)
		exit(0);
	if (ft_isvalid_args(argv) == 0)
		invalid_case_exit("Error\n");
	array = ft_calloc(argc - 1, sizeof(int));
	if (array == NULL)
		exit(1);
	loop.i = 1;
	while (argv[loop.i])
	{
		array[loop.i - 1] = ft_atoi(argv[loop.i]);
		loop.i++;
	}
	compression_array = check_duplicates_and_compression(array, argc - 1);
	free(array);
	if (compression_array == NULL)
		invalid_case_exit("Error\n");
	return (compression_array);
}

static void	invalid_case_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

static int	ft_isvalid_args(char **argv)
{
	t_check_arg	chk;

	chk.loop.i = 1;
	while (argv[chk.loop.i])
	{
		chk.loop.j = 0;
		chk.res = 0;
		while (argv[chk.loop.i][chk.loop.j])
		{
			if (!ft_isdigit(argv[chk.loop.i][chk.loop.j])
				&& !ft_issign(argv[chk.loop.i][chk.loop.j])
				&& !ft_isspace(argv[chk.loop.i][chk.loop.j]))
				return (0);
			if (!ft_issign(argv[chk.loop.i][chk.loop.j]))
				chk.res = chk.res * 10 + (argv[chk.loop.i][chk.loop.j] - '0');
			if ((!ft_strchr(argv[chk.loop.i], '-') && chk.res > INT_MAX)
				|| (ft_strchr(argv[chk.loop.i], '-') && chk.res * -1 < INT_MIN))
				return (0);
			chk.loop.j++;
		}
		if (chk.loop.j == 0 || (chk.res != 0 && ft_atoi(argv[chk.loop.i]) == 0))
			return (0);
		chk.loop.i++;
	}
	return (1);
}

static int	*check_duplicates_and_compression(int *array, int size)
{
	int		*compressed_array;
	t_loop	loop;

	compressed_array = ft_calloc(size, sizeof(int));
	if (!compressed_array)
		return (free(array), NULL);
	loop.i = 1;
	while (loop.i < size)
	{
		loop.j = 0;
		while (loop.j < loop.i)
		{
			if (array[loop.i] == array[loop.j])
				return (free(compressed_array), NULL);
			if (array[loop.i] < array[loop.j])
				compressed_array[loop.j]++;
			else
				compressed_array[loop.i]++;
			loop.j++;
		}
		loop.i++;
	}
	return (compressed_array);
}
