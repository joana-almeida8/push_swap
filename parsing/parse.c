/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:03:46 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/09 15:47:05 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_num(char *str, int j)
{
	if ((str[j] == '-' || str[j] == '+'))
		j++;
	while (ft_isdigit(str[j]) == 1)
		j++;
	return (j);
}

int	check_double(long *array, int k, long num)
{
	int	i;

	i = 0;
	while (i < k)
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i +1]) == 1)
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
	if ((res * sign) < INT_MIN || (res * sign) > INT_MAX)
		return (ft_printf("MINMAX Error\n"), exit(1), 1);
	return (res * sign);
}

int	fill_array(char **av, int i, int k, long *args)
{
	int		end;
	int		j;
	char	*substr;

	j = 0;
	while (av[i][j])
	{
		end = j;
		if (ft_isdigit(av[i][j]) == 1 || av[i][j] == '-' || av[i][j] == '+')
		{
			end = find_num(av[i], j);
			substr = ft_substr(av[i], j, end);
			if (!substr)
				return (0);
			args[k] = ft_atol(substr);
			if (check_double(args, k, args[k]) == 1)
				return (free_str(substr), ft_printf("Double Error\n"), exit(1), 1);
			k++;
			free_str(substr);
			j = end;
		}
		else 
			j++;
	}
	return (1);
}

long	*parse_to_array(long *args, char **av, int i)
{
	int	k;
	int	j;

	k = 0;
	while (av[i])
	{
		j = 0;
		fill_array(av, i, k, args);
		i++;
	}
	return (args);
}
