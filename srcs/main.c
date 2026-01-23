/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:25:29 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/23 10:19:26 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*input;
	int		len;
	int		*tmp_array;

	if (ac <= 2)
		return (0);
	len = count_nums(ac, av);
	input = malloc(len * sizeof(int));
	if (!input)
		return (write(2, "Error\n", 6), 0);
	input = parse_to_array(input, av, 1);
	if (!input)
		return (write(2, "Error\n", 6), 0);
	tmp_array = init_tmp_array(input, len);
	if (!tmp_array)
		return (free(input), ft_printf("Error\n"), 0);
	a = init_stack(NULL, input, tmp_array, len);
	b = init_stack(NULL, NULL, NULL, len);
	if (!a || !b)
		return (write(2, "Error\n", 6), free_all(a, b, input), 0);
	if (!operate_stacks(a, b))
		return (0);
	return (free_all(a, b, input), 0);
}
