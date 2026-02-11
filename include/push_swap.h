/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 08:13:40 by jreis-de          #+#    #+#             */
/*   Updated: 2026/02/11 08:04:05 by jreis-de         ###   ########.fr       */
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

// STRUCTURES //
typedef struct s_stack
{
	unsigned int	capacity;
	unsigned int	size;
	int				*array;
	int				*tmp_array;
}	t_stack;

// ALGORITHM //
int		operate_stacks(t_stack *a, t_stack *b);
int		smallest_nbr_index(t_stack *a);
int		get_chunk_max(int chunk, int chunks_nbr, int chunk_size, t_stack *a);
int		get_chunks_nbr(t_stack *a);
int		*init_tmp_array(int	*input, int len);

void	sort_3(t_stack *a);
void	sort_4_base(t_stack *a, t_stack *b);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5_base(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

void	big_swap(t_stack *a, t_stack *b);
void	sort_tmp_array(int *tmp_array, int *input, int len);
void	pre_sort_b(int chunks_nbr, t_stack *a, t_stack *b);
void	ft_swap(int *a, int *b);

void	turk_push_to_a(t_stack *a, t_stack *b);
int		turk_get_target(t_stack *a, t_stack *b, int idx_b);
void	stacks_double_rots(t_stack *a, t_stack *b, int *rot_a, int *rot_b);
void	rotate_final_stack(t_stack *s, int *rot_s, char flag);

void	calc_cost_push_b(unsigned int index, t_stack *a, t_stack *b);
void	calc_cost_rotation(t_stack *a, t_stack *b, int *rot_a, int *rot_b);
int		calc_total_cost(t_stack *a, t_stack *b, int pos_a, int pos_b);

// OPERATIONS //
void	swap(t_stack *s);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);
void	push(t_stack *from, t_stack *to);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	reverse(t_stack *s);
void	reverse_a(t_stack *a);
void	reverse_b(t_stack *b);
void	reverse_ab(t_stack *a, t_stack *b);

// PARSING //
t_stack	*init_stack(t_stack *s, int *input, int	*tmp_array, int len);
void	free_all(t_stack *a, t_stack *b, int *input);
void	*free_str(char *str);

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
char	*ft_substr(char *s, unsigned int start, unsigned int len);
size_t	ft_strlen(const char *str);
void	ft_pstr_fd(char *s, int fd);

int		ft_printf(const char *str, ...);
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *str);
int		ft_putnbr_address_pf(unsigned long n, int base);
int		ft_putnbr_base_pf(long n, int base);
int		ft_putnbr_base_upper_pf(long n, int base);
int		ft_putnbr_unsigned_pf(unsigned long n);

#endif