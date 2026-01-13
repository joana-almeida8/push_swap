/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:55:12 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/12 16:17:47 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse(t_stack *s)
{
	int				tmp;
	unsigned int	size;

	if (s->size < 2)
        return;
	size = s->size -1;
	tmp = s->array[size];
	while (size >= 1)
	{
		s->array[size] = s->array[size - 1];
		size--;
	}
	s->array[0] = tmp;
}

void	reverse_a(t_stack *a)
{
	reverse(a);
	ft_printf("rra\n");
}

void	reverse_b(t_stack *b)
{
	reverse(b);
	ft_printf("rrb\n");
	
}

void	reverse_ab(t_stack *a, t_stack *b)
{
	reverse_a(a);
	reverse_b(b);
	ft_printf("rrr\n");
}

/* array = {0, 1, 2, 3, 4, 5};

rotate_array = {5, 0, 1, 2, 3, 4};
reverse_array = {1, 2, 3, 4, 5, 0}; */