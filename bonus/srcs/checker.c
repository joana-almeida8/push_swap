/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:32:47 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/22 10:59:57 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*input;
	int		len;
	int		*tmp_array;

	if (ac < 2)
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
		return (free(input), write(2, "Error\n", 6), 0);
	a = init_stack(NULL, input, tmp_array, len);
	b = init_stack(NULL, NULL, NULL, len);
	if (!a || !b)
		return (write(2, "Error\n", 6), free_all(a, b, input), 0);
	checker(a, b);
	return (free_all(a, b, input), 0);
}
