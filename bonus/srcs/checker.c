/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:32:47 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/23 13:43:27 by jreis-de         ###   ########.fr       */
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
		return (ft_pstr_fd("Error\n", 2), 0);
	input = parse_to_array(input, av, 1);
	if (!input)
		return (ft_pstr_fd("Error\n", 2), 0);
	tmp_array = init_tmp_array(input, len);
	if (!tmp_array)
		return (free(input), ft_pstr_fd("Error\n", 2), 0);
	a = init_stack(NULL, input, tmp_array, len);
	b = init_stack(NULL, NULL, NULL, len);
	if (!a || !b)
		return (ft_pstr_fd("Error\n", 2), free_all(a, b, input), 0);
	checker(a, b);
	return (free_all(a, b, input), 0);
}
