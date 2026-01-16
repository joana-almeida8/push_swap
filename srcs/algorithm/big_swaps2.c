/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_swaps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:54:49 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/16 17:58:46 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	turc_get_target(t_stack *a, t_stack *b)
{
	int	index;
	int	target_idx;

	index = 0;
	target_idx = -1;
	while (index < (int)a->size - 1)
	{
		if (b->array[0] > a->array[index] && b->array[0] < a->array[index + 1])
			target_idx = index + 1;
		index++;
	}
	if (target_idx != -1)
		return (target_idx);
	if (b->array[0] < a->array[0] && a->array[a->size -1] < b->array[0])
		return (0);
	index = 0;
	target_idx = 0;
	while (index < (int)a->size)
	{
		if (a->array[index] > a->array[target_idx])
			target_idx = index;
		index++;
	}
	return (target_idx + 1);
}

void	turc_push_to_a(t_stack *a, t_stack *b)
{
	int	target_pos;

	while (b->size > 0)
	{
		target_pos = turc_get_target(a, b);
		if (target_pos < (int)a->size / 2)
		{
			while (target_pos-- > 0)
				rotate_a(a);
		}
		else
		{
			while (target_pos < (int)a->size)
			{
				reverse_a(a);
				target_pos++;
			}
		}
		push_a(a, b);
	}
}

// 6 2 3 4 5 1 