/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 08:13:40 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/07 11:34:09 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBRARIES
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>

// STRUCTURES
typedef struct s_stack
{
	size_t	capacity;
	size_t	size;
	long	*array;
}	t_stack;

// UTILS
t_stack	*init_stack(t_stack *a, long *input, size_t len);
void	*free_str(char **str);
void	*free_array(long **array);

// COUNT_NUMBRS
int		validate_input(char *str);
int		arg_check_num(char *str);
size_t	count_nums(int ac, char **av);
int		ft_isdigit(char c);
int		minmax_check(char *str, int j);

// PARSE_TO_NUMBRS
long	*parse_to_array(long *args, char **av, int i);
int		check_double(long *array, int num);
int		find_num(char *str, int j);
long	ft_atol(char *str);
int		fill_array(char **av, int i, int k, long *args);

// OPERATIONS
void	push();

// LIBFT
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);

// PRINTF
int		ft_printf(const char *str, ...);
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *str);
int		ft_putnbr_address_pf(unsigned long n, int base);
int		ft_putnbr_base_pf(long n, int base);
int		ft_putnbr_base_upper_pf(long n, int base);
int		ft_putnbr_unsigned_pf(unsigned long n);

#endif