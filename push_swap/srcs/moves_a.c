/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:55:51 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/13 15:19:31 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	ra(t_stack **stack_a)
{
	translate_lstup(stack_a);
	ft_printf("ra\n");
}

void	rra(t_stack **stack_a)
{
	translate_lstdwn(stack_a);
	ft_printf("rra\n");
}
