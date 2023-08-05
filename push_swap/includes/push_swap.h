/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:27:42 by svikornv          #+#    #+#             */
/*   Updated: 2023/08/05 10:27:48 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	long	data;
	struct s_stack *next;
	int	indx;
	int	len;
	int	max_digits;
	int	max_num;
}		t_stack;

typedef	struct s_vars
{
	int	characters;
}		t_vars;
//main.c
t_stack	*init_stack(void);
void	check_tab(char **argv, int i);
void	get_val(t_stack **stack_a, char *arg);
void	num_to_stack(t_stack **stack_a, int num);
void	free_stack(t_stack *stack);

//error.c
void	ft_error(long num, char *arg_split, t_stack *stack_a);
void	check_dup(t_stack *stack_a);
void	check_sort(t_stack *stack_a);
void	err_exit(t_stack *stack);
void	free_stack(t_stack *stack);

//operations.c
void	swap(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b);
void	translate_lstup(t_stack **stack);
void	translate_lstdwn(t_stack **stack);

//moves_a.c
void	sa(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);

//moves_b.c
void	sb(t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rrb(t_stack **stack_b);

//small_sort.c
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	push_smallest(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min(t_stack *stack_a);

//radix_sort.c
int	get_bits(t_stack *stack_a);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	radix(t_stack **stack_a, t_stack **stack_b, int lstlen, int i);

//push_swap.c
void	push_swap(t_stack **stack_a, t_stack **stack_b);
t_stack	*min_node(t_stack **stack_a);
void	sort_indx(t_stack **stack_a);
#endif