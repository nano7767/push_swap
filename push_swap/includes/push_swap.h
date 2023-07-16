/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:27:42 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/16 12:05:14 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int	data;
	struct s_stack *next;
	int	len;
	int	max_digits;
}		t_stack;

//main.c
void	get_max_digits(t_stack *stack_a, int num);
void	num_to_stack(t_stack **stack_a, int num);
t_stack	*ft_stacklast(t_stack *stack_a);


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
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	push_smallest(t_stack **stack_a, t_stack **stack_b);

//radix_sort.c
void	radix_sort(t_stack **stack_a);
int		get_digit(int num, int digit);

//push_swap.c
void	push_swap(t_stack **stack_a, t_stack **stack_b);
#endif