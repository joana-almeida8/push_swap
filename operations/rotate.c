/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:12:21 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/08 10:55:28 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *s)
{
	int	i;
	int	size;
	
	i = 0;
	size = s->size;
	s->array[0] = s->array[size];
	while (size >= 1)
	{
		s->array[size] = s->array[size -1];
		size--;
	}
}

void	rb(t_stack *s)
{
	int	i;
	int	size;
	
	i = 0;
	size = s->size;
	s->array[0] = s->array[size];
	while (size >= 1)
	{
		s->array[size] = s->array[size -1];
		size--;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	ra(a);
	rb(b);
}

/* array = {0, 1, 2, 3, 4, 5};

rotate_array = {5, 0, 1, 2, 3, 4};
reverse_array = {1, 2, 3, 4, 5, 0}; */