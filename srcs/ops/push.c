/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:45:47 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/20 10:34:53 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	unsigned long	i;

	if (from->size == 0 || to->size >= to->capacity)
		return ;
	i = to->size;
	while (i > 0)
	{
		to->array[i] = to->array[i - 1];
		i--;
	}
	to->array[0] = from->array[0];
	to->size++;
	i = 0;
	while (i < from->size - 1)
	{
		from->array[i] = from->array[i + 1];
		i++;
	}
	from->size--;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}
