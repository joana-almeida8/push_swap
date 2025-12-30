#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h> 

/* typedef struct    s_list
{
    struct s_list *next;
    int			*value;
}                 t_list; */

typedef struct s_stack
{
	unsigned int capacity;
	int	size;
	int	*array;
} t_stack;

// PARSING
int	validate_input(char *str);
int	arg_check_num(char *str);
int	count_nums(int ac, char **av);
int	ft_isdigit(char c);

// OPERATIONS
void	push();


// LIBFT
int	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

// PRINTF
int	ft_printf(const char *str, ...);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_address_pf(unsigned long n, int base);
int	ft_putnbr_base_pf(long n, int base);
int	ft_putnbr_base_upper_pf(long n, int base);
int	ft_putnbr_unsigned_pf(unsigned long n);

#endif