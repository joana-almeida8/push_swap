/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:55:12 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/08 10:56:05 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *s)
{
	int		i;
	long	tmp;
	
	i = 0;
	tmp = s->array[0];
	while (s->array[i +1])
	{
		s->array[i] = s->array[i +1];
		i++;
	}
	s->array[i] = tmp;
}

void	rrb(t_stack *s)
{
	int		i;
	long	tmp;
	
	i = 0;
	tmp = s->array[0];
	while (s->array[i +1])
	{
		s->array[i] = s->array[i +1];
		i++;
	}
	s->array[i] = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rra(a);
	rrb(b);
}

/* array = {0, 1, 2, 3, 4, 5};

rotate_array = {5, 0, 1, 2, 3, 4};
reverse_array = {1, 2, 3, 4, 5, 0}; */