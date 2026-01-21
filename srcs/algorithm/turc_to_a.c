/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turc_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:54:49 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/20 10:11:31 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	turc_get_target(t_stack *a, t_stack *b, int idx_b)
{
	int		index;
	int		target_idx;
	long	closest_big;

	index = 0;
	target_idx = -1;
	closest_big = (long)INT_MAX + 1;
	while (index < (int)a->size)
	{
		if (b->array[idx_b] < a->array[index] && a->array[index] < closest_big)
		{
			closest_big = a->array[index];
			target_idx = index;
		}
		index++;
	}
	if (target_idx == -1)
		return (smallest_nbr_index(a));
	return (target_idx);
}

void	stacks_double_rots(t_stack *a, t_stack *b, int *rot_a, int *rot_b)
{
	if (*rot_a >= (int)a->size / 2 && *rot_b >= (int)b->size / 2)
	{
		while (*rot_a <= (int)a->size - 1 && *rot_b <= (int)b->size - 1)
		{
			reverse_ab(a, b);
			(*rot_a)++;
			(*rot_b)++;
		}
	}
	else if (*rot_a < (int)a->size / 2 && *rot_b < (int)b->size / 2)
	{
		while (*rot_a > 0 && *rot_b > 0)
		{
			rotate_ab(a, b);
			(*rot_a)--;
			(*rot_b)--;
		}
	}
}

void	rotate_final_stack(t_stack *s, int *rot_s, char flag)
{
	if (*rot_s >= (int)s->size / 2)
	{
		while (*rot_s < (int)s->size)
		{
			if (flag == 'a')
				reverse_a(s);
			else if (flag == 'b')
				reverse_b(s);
			(*rot_s)++;
		}
	}
	else
	{
		while (*rot_s > 0)
		{
			if (flag == 'a')
				rotate_a(s);
			else if (flag == 'b')
				rotate_b(s);
			(*rot_s)--;
		}
	}
}

void	turc_push_to_a(t_stack *a, t_stack *b)
{
	int	rot_a;
	int	rot_b;

	while ((int)b->size > 0)
	{
		calc_cost_rotation(a, b, &rot_a, &rot_b);
		stacks_double_rots(a, b, &rot_a, &rot_b);
		if (rot_a > 0)
			rotate_final_stack(a, &rot_a, 'a');
		if (rot_b > 0)
			rotate_final_stack(b, &rot_b, 'b');
		push_a(a, b);
	}
}
