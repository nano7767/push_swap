/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:42:12 by svikornv          #+#    #+#             */
/*   Updated: 2023/08/04 11:09:59 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	sort_indx(stack_a);
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
		radix_sort(stack_a, stack_b);
	// ptr = *stack_a;
	// while (ptr)
	// {
	// 	ft_printf("%d ", ptr->data);
	// 	ptr = ptr->next;
	// }
}

t_stack	*min_node(t_stack **stack_a)
{
	t_stack	*min;
	t_stack	*ptr;

	ptr = *stack_a;
	min = NULL;
	while (ptr)
	{
		if ((min == NULL && ptr->indx == 0) || (ptr->indx == 0 && ptr->data < min->data))
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}

void	sort_indx(t_stack **stack_a)
{
	t_stack	*ptr;
	t_stack	*tmp;
	int		i;

	ptr = *stack_a;
	i = 1;
	while (ptr)
	{
		tmp = min_node(stack_a);
		tmp->indx = i;
		ptr = ptr->next;
		i++;
	}
}


//CHANGE MIN INDX TO I++ ONLY IF DOESNT HAVE AN INDX ALREADY.