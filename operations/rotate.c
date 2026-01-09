/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:12:21 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/09 15:44:43 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *s, int	print_check)
{
	unsigned long	i;
	unsigned long	tmp;
	
	i = 0;
	tmp = s->array[0];
	while (i < (s->size - 1))
	{
		s->array[i] = s->array[i +1];
		i++;
	}
	s->array[i] = tmp;
	if (print_check == 0)
		ft_printf("ra\n");
}

void	rb(t_stack *s, int	print_check)
{
	unsigned long	i;
	unsigned long	tmp;
	
	i = 0;
	tmp = s->array[0];
	while (i < (s->size - 1))
	{
		s->array[i] = s->array[i +1];
		i++;
	}
	s->array[i] = tmp;
	if (print_check == 0)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr\n");
}

/* array = {0, 1, 2, 3, 4, 5};

rotate_array = {5, 0, 1, 2, 3, 4};
reverse_array = {1, 2, 3, 4, 5, 0}; */