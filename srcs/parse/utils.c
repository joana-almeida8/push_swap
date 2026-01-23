/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:09:06 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/23 10:42:05 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_all(t_stack *a, t_stack *b, int *input)
{
	if (input)
		free(input);
	if (a)
		free(a);
	if (b)
	{
		if (b->array)
			free(b->array);
		free(b);
	}
}

void	*free_str(char *str)
{
	free(str);
	return (NULL);
}

t_stack	*init_stack(t_stack *s, int *input, int	*tmp_array, int len)
{
	int	*inputb;

	s = malloc(sizeof(t_stack));
	if (!s)
	{
		ft_pstr_fd("Error\n", 2);
		exit(1);
	}
	s->capacity = len;
	if (input)
	{
		s->size = len;
		s->array = input;
		s->tmp_array = tmp_array;
	}
	else
	{
		s->size = 0;
		inputb = malloc(len * sizeof(int));
		if (!inputb)
			return (NULL);
		s->array = inputb;
		s->tmp_array = NULL;
	}
	return (s);
}
