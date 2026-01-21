/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:12:21 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/20 10:34:39 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *s)
{
	unsigned int	i;
	int				tmp;

	if (s->size < 2)
		return ;
	i = 0;
	tmp = s->array[0];
	while (i < (s->size - 1))
	{
		s->array[i] = s->array[i +1];
		i++;
	}
	s->array[s->size - 1] = tmp;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
