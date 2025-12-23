#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h> 

typedef struct s_stack 
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// OPERATIONS
void	push(t_stack **stack_from, t_stack **stack_to);

// PRINTF
int	ft_printf(const char *str, ...);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_address_pf(unsigned long n, int base);
int	ft_putnbr_base_pf(long n, int base);
int	ft_putnbr_base_upper_pf(long n, int base);
int	ft_putnbr_unsigned_pf(unsigned long n);

#endif