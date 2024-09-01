/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:23:15 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/30 21:23:44 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_issimbol(char c)
{
	return (c == '-' || c == '+');
}