/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:15:14 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/21 16:55:39 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../../include/push_swap.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	a_is_sorted(t_stack *a)
{
	unsigned int	index;

	index = 0;
	while (index < a->size - 2)
	{
		if (a->array[index] < a->array[index + 1])
			index++;
		else
			return (0);
	}
	if (index == a->size - 1)
		return (1);
	return (0);
}

int	check_ops2(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp("ra\n", line, 3))
		rotate(a);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate(b);
	else if (!ft_strncmp("rr\n", line, 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp("rra\n", line, 4))
		reverse(a);
	else if (!ft_strncmp("rrb\n", line, 4))
		reverse(b);
	else if (!ft_strncmp("rrr\n", line, 4))
	{
		rotate(a);
		rotate(b);
	}
	else
		return (ft_printf("Error\n"),0);
	return (1);
}

int	check_ops(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp("sa\n", line, 3))
		swap(a);
	else if (!ft_strncmp("sb\n", line, 3))
		swap(b);
	else if (!ft_strncmp("ss\n", line, 3))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp("pa\n", line, 3))
		push(a, b);
	else if (!ft_strncmp("pb\n", line, 3))
		push(b, a);
	else
		return (check_ops2(a, b, line));
	return (1);
}

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_ops(a, b, line))
		{
			free (line);
			return ;
		}
		line = get_next_line(0);
	}
	if (a_is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
