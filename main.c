/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:25:29 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/15 15:33:20 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int		*input;
	int		len;

	if (ac < 2)
		return (ft_printf("Error\n"), 0);
	len = count_nums(ac, av);
	input = malloc(len * sizeof(int));
	if (!input)
		return (ft_printf("Error\n"), 0);
	input = parse_to_array(input, av, 1);
	if (!input)
		return (ft_printf("Error\n"), 0);
	a = init_stack(NULL, input, len);
	b = init_stack(NULL, NULL, len);
	if (!a || !b)
		return (ft_printf("Error\n"), free_all(a, b, input), 0);
	if (!operate_stacks(a, b))
		return (0);
	return (ft_printf("Error\n"), free_all(a, b, input), 0);
}
