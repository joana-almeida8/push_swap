/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:18:42 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/07 11:39:50 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	minmax_check(char *str, int j)
{
	int	count;

	count = 0;
	while (ft_isdigit(str[j]) == 1)
	{
		count++;
		j++;
	}
	if (count <= 10)
		return (1);
	return (0);
}

int	validate_input(char *str)
{
	int	j;
	int	check;

	j = 0;
	check = 0;
	while (str[j])
	{
		if (j > 0)
		{
			if (ft_isdigit(str[j -1]) == 1
				&& (str[j] > 32 && !ft_isdigit(str[j])))
				return (0);
		}
		if (((str[j] == '+' || str[j] == '-') && (str[j +1] == '+'
					|| str[j +1] == '-')) || (ft_isdigit(str[j]) != 1
				&& str[j] != '+' && str[j] != '-' && str[j] > 32))
			return (0);
		if (ft_isdigit(str[j]) == 1)
		{
			if (minmax_check(str, j) == 1)
				check = 1;
		}
		j++;
	}
	return (check);
}

int	arg_check_num(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] <= 32)
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (!ft_isdigit(str[i +1]))
				return (0);
			i++;
		}
		if (ft_isdigit(str[i]) == 1)
		{
			// ft_printf("%d, %c\n", count, str[i]);
			count++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
	}
	// ft_printf("%d\n", count);
	return (count);
}

size_t	count_nums(int ac, char **av)
{
	size_t	count;
	int		i;

	if (ac > 1)
	{
		count = 0;
		i = 1;
		while (i < ac)
		{
			if (!validate_input(av[i]))
			{
				// ft_printf("%s", av[i]);
				ft_printf("Error1\n");
				exit(1);
			}
			count += arg_check_num(av[i]);
			i++;
		}
		// ft_printf("Count: %d\n", count);
		return (count);
	}
	return (0);
}
