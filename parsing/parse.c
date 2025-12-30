/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:03:46 by jreis-de          #+#    #+#             */
/*   Updated: 2025/12/30 16:29:04 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	arg_check(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i] <= 32 || str[i] == '+' || str[i] == '-')
		i++;
	if (ft_isdigit(str[i]) == 1)
	{
		check = 1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
		i++;
	while (str[i] <= 32)
		i++;
	if (ft_isdigit(str[i]) == 1)
	{
		check = 2;
		i++;
	}
	if (str[i] > 32 && is_num(str[i]) == 0)
		check = 0;
	return (check);
}

int	*parse_to_array(int ac, char **av, int i, int j)
{
	int	*args;

	args = malloc((count_num(ac, av) + 1) * sizeof(int));
	if (!args)
		return (0);
	while (av[i])
	{
		if (arg_check(av[i]) == 1)
		{
			args[j] = ft_atol(av[i]);
			if (args == 4444422222)
				return (0);
		}
		else if (arg_check(av[i]) == 0)
			return (0);
		else if (arg_check(av[i]) == 2)
		{
			args[j] = 424242;
		}
		i++;
		j++;
	}
	return (args);
}

















		
		/* if (ft_atol(str[i]) <= INT_MAX)
			args[j] = ft_atol(str[i]);
		else if (ft_atol(str[i]) == 4444422222)
			return (0);
		else if (ft_atol(str[i]) == 2222244444)
		{
			
			j++;
		}
		i++;
		j++;
	}
	return (args);
} */
