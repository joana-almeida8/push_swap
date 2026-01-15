/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:22:24 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/15 15:33:23 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* int	smallest_nbr_index(t_stack *a)
{
	unsigned int	i;
	int				min;
	unsigned int	min_pos;

	i = 0;
	min = a->array[0];
	min_pos = 0;
	while (i < a->size)
	{
		if (a->array[i] < min)
		{
			min = a->array[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
} */

int	operate_stacks(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			swap_a(a);
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		return (big_swap(a, b));
	return (1);
}
