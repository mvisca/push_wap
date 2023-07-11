/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:01:20 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/11 12:26:46 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_tab(char **tab)
{
	int	i;

	if (!tab && !(*tab))
		return ;
	ft_printf ("\n======== Print TAB ==========\n");
	if (!tab)
		ft_printf ("-------- TAB (null)\n");
	i = 0;
	while (tab && tab[i])
	{
		ft_printf("tab[%d] %s\n", i, tab[i]);
		i++;
	}
}

void	print_stack(t_stack *stack, char *name)
{
	t_list	*aux;
	int		i;

	ft_printf("\n======== Print '%s' ==========\n", name);
	ft_printf("-------- Nodes\n", name);
	aux = stack->head;
	i = 0;
	while (aux)
	{
		ft_printf("Node [%d]\t-> Content: %d\n", (1 + i++), *(aux->content));
		aux = aux->next;
	}
	stack->size = ft_lstsize(stack->head);
	ft_printf("\n-------- Stats\n", name);
	ft_printf("* Max %d\n", stack->max);
	ft_printf("* Min %d\n", stack->min);
	ft_printf("* Size %d\n", stack->size);
	ft_printf("======== END '%s'\n", name);
}

static void	*print_line(int cont)
{
	int	len;

	len = 0;
	if (cont == 0)
	{
		ft_printf(" 0 ");
		len = 3;
	}
	else
		len = ft_printf(" %d", cont);
	len = 16 - len;
	while (len > 0 && ft_printf(" "))
		len--;
	ft_printf("| ");
	return (NULL);
}

void	print_stacks(t_list *a, t_list *b)
{
	ft_printf("\n ===== a ====== | ====== b ===== \n");
	while (a || b)
	{
		if (a)
		{
			print_line(*(a->content));
			a = a->next;
		}
		else
			ft_printf("                | ");
		if (b && !print_line(*(b->content)))
			b = b->next;
		else
			ft_printf("                |");
		ft_printf("\n");
	}
	ft_printf(" ===== a ====== | ====== b ===== \n\n");
}

void	test_moves(t_stack **a, t_stack **b)
{
	print_stacks((*a)->head, (*b)->head);
	make_a(sa, *a, *b);
	make_a(pb, *a, *b);
	make_a(pb, *a, *b);
	make_a(pb, *a, *b);
	make_a(rr, *a, *b);
	make_a(rrr, *a, *b);
	make_a(sa, *a, *b);
	make_a(pa, *a, *b);
	make_a(pa, *a, *b);
	make_a(pa, *a, *b);
	print_stacks((*a)->head, (*b)->head);
}

void	manual_sort(t_stack **a, t_stack **b)
{
	char	buffer[3];
	int		readed;

	while (1)
	{
		print_stacks((*a)->head, (*b)->head);
		ft_printf("Ingrese una opción: [pa, pb, sa, sb, ss, ra, rb, rra, rrb, rrr, end]:\n");
		readed = read(STDIN_FILENO, buffer, 3);
		if (readed == -1)
			return ;
		ft_printf("Su opcion: %s\n", buffer);
		if (ft_strncmp(buffer, "pa", 2) == 0)
			make_a(pa, *a, *b);
		else if (ft_strncmp(buffer, "pb", 2) == 0)
			make_a(pb, *a, *b);
		else if (ft_strncmp(buffer, "sa", 2) == 0)
			make_a(sa, *a, *b);
		else if (ft_strncmp(buffer, "sb", 2) == 0)
			make_a(sb, *a, *b);
		else if (ft_strncmp(buffer, "ss", 2) == 0)
			make_a(ss, *a, *b);
		else if (ft_strncmp(buffer, "ra", 2) == 0)
			make_a(ra, *a, *b);
		else if (ft_strncmp(buffer, "rb", 2) == 0)
			make_a(rb, *a, *b);
		else if (ft_strncmp(buffer, "rr", 2) == 0)
			make_a(rr, *a, *b);
		else if (ft_strncmp(buffer, "rra", 3) == 0)
			make_a(rra, *a, *b);
		else if (ft_strncmp(buffer, "rrb", 3) == 0)
			make_a(rrb, *a, *b);
		else if (ft_strncmp(buffer, "rrr", 3) == 0)
			make_a(rrr, *a, *b);
		else if (ft_strncmp(buffer, "end", 3) == 0)
			return ;
		else
			ft_printf("Opcion no válida\n");
	}
}