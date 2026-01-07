/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:03:46 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/07 11:35:53 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_num(char *str, int j)
{
	// ft_printf("str: %s\n", str);
	// while (str[j] <= 32)
	// 	j++;
	while (ft_isdigit(str[j]) == 1 || (str[j] == '-' || str[j] == '+'))
	{
		// ft_printf("str[j]: %c\n", str[j]);
		j++;
	}
	return (j);
}

int	check_double(long *array, int num)
{
	int	i;

	i = 0;
	while (i < num)
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
	sign = 0;
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
	// ft_printf("%d\n", (res * sign));
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
			// ft_printf("j: %d, end:%d\n", j, end);
			substr = ft_substr(av[i], j, end);
			if (!substr)
				return (0);
			args[k] = ft_atol(substr);
			free_str(&substr);
			if (check_double(args, args[k]) == 1)
				return (ft_printf("Double Error\n"), exit(1), 1);
			k++;
		}
		j = end + 1;
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
