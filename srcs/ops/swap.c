/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:35:48 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/20 10:34:49 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->array[0];
	s->array[0] = s->array[1];
	s->array[1] = tmp;
}

void	swap_a(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
