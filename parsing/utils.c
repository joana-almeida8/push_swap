/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:18:42 by jreis-de          #+#    #+#             */
/*   Updated: 2025/12/30 17:25:00 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
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
			if (ft_isdigit(str[j-1]) == 1 && (str[j] > 32 && !ft_isdigit(str[j])))
				return (0);
		}
		if ((str[j] == '+' || str[j] == '-') 
			&& (str[j+1] == '+' || str[j+1] == '-'))
				return (0);
		if (ft_isdigit(str[j]) == 1)
			check = 1;
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
		while (str[i] <= 32 || str[i] == '+' || str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 1)
		{
			count++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
	}
	return (count);
}

int	count_nums(int ac, char **av)
{
	int	count;
	int	i;

	if (ac > 1)
	{
		count = 0;
		i = 1;
		while (av[i])
		{
			if (validate_input(av[i]) == 1)
				count += arg_check_num(av[i]);
			else
				return (0);
			i++;
		}
		return (count);	
	}
	return (0);
}

/* long	ft_atol(char *str)
{
	long res;
	int	sign;
	int	i;

	i = 0;
	while (str[i] <= 32)
		i++;
	sign = 0;
	if (str[i] == '-' || str[i] == '+' && ft_isdigit(str[i+1]) == 1)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (res <= INT_MAX && str[i] == '\0')
		return (res * sign);
	else if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
		return (2222244444);
	return (4444422222);
} */

/// 2222244444 --> There are other numbers after. Trigger the isspace_checker.
/// 4444422222 --> Error message. E.g.: other characters are letters, or number is bigger than INT-MAX.