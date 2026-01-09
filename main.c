/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:25:29 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/09 14:05:34 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	long	*input;
	size_t	len;

	if (ac < 2)
		return (ft_printf("Error4\n"), 0);
	len = count_nums(ac, av);
	input = malloc(len * sizeof(long));
	if (!input)
		return (ft_printf("Error2\n"), 0);
	input = parse_to_array(input, av, 1);
	if (!input)
		return (ft_printf("Error3\n"), 0);
	a = init_stack(NULL, input, len);
	b = init_stack(NULL, NULL, len);
	if (!a || !b)
		return (free_all(a, b, input), 0);
	operate_stack(a, b);
	return (free_all(a, b, input), 0);
}
