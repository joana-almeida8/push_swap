/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 08:13:40 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/15 15:33:39 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBRARIES
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
//# include <stdio.h>

/* # include <stdlib.h>
# include <stddef.h>
# include <stdbool.h> */

// STRUCTURES //
typedef struct s_stack
{
	unsigned int	capacity;
	unsigned int	size;
	int				*array;
}	t_stack;


// ALGORITHM //
int		operate_stacks(t_stack *a, t_stack *b);
//int		smallest_nbr_index(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4_base(t_stack *a, t_stack *b);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5_base(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
int		big_swap(t_stack *a, t_stack *b);


// OPERATIONS //
void	swap(t_stack *s);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);
void	push(t_stack *from, t_stack *to);
void 	push_a(t_stack *a, t_stack *b);
void 	push_b(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	reverse(t_stack *s);
void	reverse_a(t_stack *a);
void	reverse_b(t_stack *b);
void	reverse_ab(t_stack *a, t_stack *b);


// PARSING //
t_stack	*init_stack(t_stack *a, int *input, unsigned int len);
void	free_all(t_stack *a, t_stack *b, int *input);
void	*free_str(char *str);
void	*free_array(int *array);

int		validate_input(char *str);
int		arg_check_num(char *str);
int		count_nums(int ac, char **av);
int		ft_isdigit(char c);
int		minmax_check(char *str, int j);

int		*parse_to_array(int *args, char **av, int i);
int		check_double(int *array, int k, long num);
int		find_num(char *str, int j);
long	ft_atol(char *str);
int		fill_array(char **av, int i, int k, int *args);


// LIBFT //
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);

int		ft_printf(const char *str, ...);
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *str);
int		ft_putnbr_address_pf(unsigned long n, int base);
int		ft_putnbr_base_pf(long n, int base);
int		ft_putnbr_base_upper_pf(long n, int base);
int		ft_putnbr_unsigned_pf(unsigned long n);

#endif