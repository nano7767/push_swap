/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:25:02 by svikornv          #+#    #+#             */
/*   Updated: 2023/08/05 08:59:44 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	tmp->next = *stack_1;
	*stack_1 = tmp;
}

void	translate_lstup(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

void	translate_lstdwn(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}
