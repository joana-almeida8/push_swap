/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:51:32 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/09 16:24:37 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	smallest_first(t_stack *a)
{
	size_t	i;
	long	min;
	size_t	min_pos;

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
	if (min_pos <= a->size / 2)
		while (min_pos--)
			ra(a, 0);
	else
		while (min_pos++ < a->size)
			rra(a, 0);
}

void	mini_swap(t_stack *a)
{
	long	n1;
	long	n2;
	long	n3;

	n1 = a->array[0];
	n2 = a->array[1];
	n3 = a->array[2];
	if (n1 < n2 && n2 < n3)
		return ;
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(a, 0);
	else if (n1 > n2 && n2 > n3)
	{
		sa(a, 0);
		rra(a, 0);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a, 0);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(a, 0);
		ra(a, 0);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a, 0);
}

void	little_swap(t_stack *a, t_stack *b)
{
	smallest_first(a);
	pb(a, b);
	mini_swap(a);
	pa(a, b);
}

void	handful_swap(t_stack *a, t_stack *b)
{
	smallest_first(a);
	pb(a, b);
	little_swap(a, b);
	pa(a, b);
}

void	operate_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a, 0);
	}
	else if (a->size == 3)
		mini_swap(a);
	else if (a->size == 4)
		little_swap(a, b);
	else if (a->size == 5)
		handful_swap(a, b);
	// else
	// 	big_swap(a, b);
}
