/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:51:32 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/16 14:05:54 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->array[0];
	n2 = a->array[1];
	n3 = a->array[2];
	if (n1 < n2 && n2 < n3)
		return ;
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		swap_a(a);
	else if (n1 > n2 && n2 > n3)
	{
		swap_a(a);
		reverse_a(a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		rotate_a(a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		reverse_a(a);
}

void	sort_4_base(t_stack *a, t_stack *b)
{
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
}

void	sort_4(t_stack *a, t_stack *b)
{
	if (smallest_nbr_index(a) == 0)
		sort_4_base(a, b);
	else if (smallest_nbr_index(a) == 1)
	{
		rotate_a(a);
		sort_4_base(a, b);
	}
	else if ((smallest_nbr_index(a) == 2))
	{
		rotate_a(a);
		rotate_a(a);
		sort_4_base(a, b);
	}
	else
	{
		reverse_a(a);
		sort_4_base(a, b);
	}
}

void	sort_5_base(t_stack *a, t_stack *b)
{
	push_b(a, b);
	sort_4(a, b);
	push_a(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	if (smallest_nbr_index(a) == 0)
		sort_5_base(a, b);
	else if (smallest_nbr_index(a) == 1)
	{
		rotate_a(a);
		sort_5_base(a, b);
	}
	else if (smallest_nbr_index(a) == 2)
	{
		rotate_a(a);
		rotate_a(a);
		sort_5_base(a, b);
	}
	else if (smallest_nbr_index(a) == 3)
	{
		reverse_a(a);
		reverse_a(a);
		sort_5_base(a, b);
	}
	else
	{
		reverse_a(a);
		sort_5_base(a, b);
	}
}
