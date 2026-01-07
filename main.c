/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:25:29 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/07 11:37:32 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	// t_stack *a;
	// t_stack b;
	long	*input;
	size_t	len;

	if (ac >= 2)
	{
		len = count_nums(ac, av);
		// printf("count_nums: %zu\n", len);
		input = malloc(len * sizeof(long));
		// while (*input)
		// 	ft_printf("%d, ", *input++);
		if (!input)
			return (free_array(&input), ft_printf("Error2\n"), 0);
		input = parse_to_array(input, av, 1);
		if (!input)
			return (free_array(&input), ft_printf("Error3\n"), 0);
		// a = init_stack(&a, input, len);
		// if (!a)
		// 	return (ft_printf("Error\n"), 0);
		// init_stack(&b, ac, av);
		// if (!init_stack(&b, ac, av))
		// 	return (ft_printf("Error\n"), 0);
		// operate_stack(a, b);
	}
	else
		return (ft_printf("Error4\n"));
	return (0);
}
