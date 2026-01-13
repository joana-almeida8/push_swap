/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:12:21 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/12 16:17:51 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *s)
{
	unsigned int	i;
	int				tmp;

	if (s->size < 2)
        return;
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
	rotate_a(a);
	rotate_b(b);
	ft_printf("rr\n");
}

/* array = {0, 1, 2, 3, 4, 5};

rotate_array = {5, 0, 1, 2, 3, 4};
reverse_array = {1, 2, 3, 4, 5, 0}; */