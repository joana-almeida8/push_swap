/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:55:12 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/22 10:56:19 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse(t_stack *s)
{
	int				tmp;
	unsigned int	size;

	if (s->size < 2)
		return ;
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
	reverse(a);
	reverse(b);
	ft_printf("rrr\n");
}
