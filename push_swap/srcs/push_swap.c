/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:42:12 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/13 17:35:39 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;

	ft_printf("args: \n%d\n", (*stack_a)->len);
	if ((*stack_a)->len == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if ((*stack_a)->len == 3)
		sort_three(stack_a);
	else if ((*stack_a)->len == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a);

	ptr = *stack_a;
	while (ptr)
	{
		ft_printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}