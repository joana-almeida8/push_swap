/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:59:44 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/20 10:30:06 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	calc_total_cost(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = a->size - pos_a;
	cost_b = b->size - pos_b;
	if (pos_a <= (int)a->size / 2 && pos_b <= (int)b->size / 2)
	{
		if (pos_a > pos_b)
			return (pos_a);
		else
			return (pos_b);
	}
	if (pos_a > (int)a->size / 2 && pos_b > (int)b->size / 2)
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	if (pos_a <= (int)a->size / 2)
		return (pos_a + cost_b);
	return (cost_a + pos_b);
}

void	calc_cost_rotation(t_stack *a, t_stack *b, int *rot_a, int *rot_b)
{
	unsigned int	index;
	unsigned int	pos_a;
	unsigned int	best_cost;
	unsigned int	total_cost;

	index = 0;
	best_cost = INT_MAX;
	while (index < b->size)
	{
		pos_a = turc_get_target(a, b, index);
		total_cost = calc_total_cost(a, b, pos_a, index);
		if (total_cost < best_cost)
		{
			best_cost = total_cost;
			*rot_a = pos_a;
			*rot_b = (int)index;
		}
		if (total_cost == 0)
			break;
		index++;
	}
}

void	calc_cost_push_b(unsigned int index, t_stack *a, t_stack *b)
{
	
	if (index < a->size / 2)
	{
		while (index > 0)
		{
			rotate_a(a);
			index--;
		}
		push_b(a, b);
	}
	else
	{
		while (index < a->size)
		{
			reverse_a(a);
			index++;
		}
		push_b(a, b);
	}
}
