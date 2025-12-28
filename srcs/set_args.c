/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:48:33 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/20 06:55:04 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sign(char c);
static int	*check_duplicates_and_compression(int *array, int size);
static int	validate_argument(t_check_arg *chk, char *arg);
static int	is_valid_args(char **argv);

int	*set_args(int argc, char **argv)
{
	int		*array;
	int		*compression_array;
	t_loop	loop;

	if (argc < 2)
		exit(0);
	if (is_valid_args(argv) == 0)
		return (NULL);
	array = ft_calloc(argc - 1, sizeof(int));
	if (array == NULL)
		return (NULL);
	loop.i = 1;
	while (argv[loop.i])
	{
		array[loop.i - 1] = ft_atoi(argv[loop.i]);
		loop.i++;
	}
	compression_array = check_duplicates_and_compression(array, argc - 1);
	free(array);
	if (compression_array == NULL)
		return (NULL);
	return (compression_array);
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

static int	check_sign(char c)
{
	if (c == '+')
		return (1);
	else
		return (-1);
}

static int	validate_argument(t_check_arg *chk, char *arg)
{
	chk->loop.j = 0;
	chk->res = 0;
	if (ft_issign(arg[chk->loop.j]))
		chk->sign = check_sign(arg[chk->loop.j]);
	if (ft_issign(arg[chk->loop.j]))
		chk->loop.j++;
	if (!ft_isdigit(arg[chk->loop.j]))
		return (0);
	while (arg[chk->loop.j])
	{
		if (!ft_isdigit(arg[chk->loop.j]))
			return (0);
		chk->res = chk->res * 10 + (arg[chk->loop.j++] - '0') * chk->sign;
		if (chk->res < INT_MIN || chk->res > INT_MAX)
			return (0);
	}
	return (1);
}

static int	is_valid_args(char **argv)
{
	t_check_arg	chk;

	chk.loop.i = 0;
	chk.sign = 1;
	while (argv[++chk.loop.i])
	{
		if (!validate_argument(&chk, argv[chk.loop.i]))
			return (0);
	}
	return (1);
}
