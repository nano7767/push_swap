/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:00:49 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/20 10:49:16 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

void	rb(t_stack **stack_b)
{
	translate_lstup(stack_b);
	ft_printf("rb\n");
}

void	rrb(t_stack **stack_b)
{
	translate_lstdwn(stack_b);
	ft_printf("rrb\n");
}