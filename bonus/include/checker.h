/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:05:47 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/22 10:35:40 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// LIBRARIES
# include "../../include/push_swap.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// GET_NEXT_LINE
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
void	ft_update_buffer(char *buffer);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

// CHECKER
void	checker(t_stack *a, t_stack *b);
int		ft_strncmp(char *s1, const char *s2, size_t n);
int		check_ops(t_stack *a, t_stack *b, char *line);
int		check_ops2(t_stack *a, t_stack *b, char *line);
int		a_is_sorted(t_stack *a, t_stack *b);

#endif