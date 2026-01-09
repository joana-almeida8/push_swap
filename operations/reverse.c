/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:55:12 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/09 15:23:57 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *s, int	print_check)
{
	long	tmp;
	long	size;

	size = s->size -1;
	tmp = s->array[size];
	while (size >= 1)
	{
		s->array[size] = s->array[size -1];
		size--;
	}
	s->array[0] = tmp;
	if (print_check == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack *s, int	print_check)
{
	long	tmp;
	long	size;

	size = s->size -1;
	tmp = s->array[size];
	while (size >= 1)
	{
		s->array[size] = s->array[size -1];
		size--;
	}
	s->array[0] = tmp;
	if (print_check == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rra(a, 1);
	rrb(b, 1);
	ft_printf("rrr\n");
}

/* array = {0, 1, 2, 3, 4, 5};

rotate_array = {5, 0, 1, 2, 3, 4};
reverse_array = {1, 2, 3, 4, 5, 0}; */