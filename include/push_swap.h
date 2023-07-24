/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:47 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/24 19:15:06 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef enum e_command
{
	end,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_com;

typedef struct	s_stack
{
	t_list	*head;
	int		size;
	int		max;
	int		min;
}	t_stack;

typedef struct	s_ps
{
	t_stack	*a;
	t_stack	*b;
	char	**tab;
}	t_ps;

// push_swap_commands.c
void	*ps_command(t_com move, t_ps *ps);

// push_swap_debug.c
void	print_tab(t_ps *ps);
void	print_stack(t_stack *stack, char *name);
void	print_stacks(t_ps *ps);
void	print_moves(t_com *moves);
void	test_moves(t_ps *ps);
void	manual_sort(t_ps *ps);

// push_swap_parse.c
char	**args_to_tab(int ac, char **av, char **tab);
t_stack	*tab_to_stack(char **tab, t_stack *stack);

// push_swap_sort.c
void	sort_stack(t_ps *ps);
int		move_cost(t_com *moves);

// push_swap_sort_utils_a.c
t_com	*prep_a(t_stack *a, t_list *current, t_com *test_moves);

// push_swap_sort_utils_b.c
t_com	*prep_b(t_stack *b, int num);

// push_swap_sort_utils_two.c
void    sort_two(t_ps *ps);

// push_swap_sort_utils_three.c
void	sort_three(t_ps *ps);

// push_swap_sort_long.c
void    sort_long(t_ps *ps);

// push_swap_mem_utils.c
void	*free_ps(t_ps *ps);
char	*free_tab(char ***tab);
t_stack	*free_stack(t_stack **stack);
t_stack	*alloc_stack(void);
void	update_stack(t_stack **stack);

// push_swap_validate_args.c
int		is_int(char *str);
int		only_digits(char *str);
int		tab_valid(char **tab);

#endif