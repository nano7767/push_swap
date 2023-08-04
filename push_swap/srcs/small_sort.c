/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:16:32 by svikornv          #+#    #+#             */
/*   Updated: 2023/08/04 17:51:57 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*ptr;

	ptr = *stack_a;
	if ((ptr->data > ptr->next->data) && (ptr->next->data <
		ptr->next->next->data) && (ptr->data < ptr->next->next->data))
	{
		sa(stack_a);
	}
	else if ((ptr->data > ptr->next->data) && (ptr->next->data >
		ptr->next->next->data) && (ptr->data > ptr->next->next->data))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((ptr->data > ptr->next->data) && (ptr->next->data <
		ptr->next->next->data) && (ptr->data > ptr->next->next->data))
		ra(stack_a);

	else if ((ptr->data < ptr->next->data) && (ptr->next->data >
		ptr->next->next->data) && (ptr->data < ptr->next->next->data))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((ptr->data < ptr->next->data) && (ptr->next->data >
		ptr->next->next->data) && (ptr->data > ptr->next->next->data))
		rra(stack_a);
	else if ((ptr->data > ptr->next->data))
		sa(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	push_smallest(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_smallest(stack_a, stack_b);
	push_smallest(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	push_smallest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *ptr;
	t_stack *min;
	int	i;

	ptr = *stack_a;
	min = ptr;
	i = 0;
	while (ptr)
	{
		if (ptr->data < min->data)
			min = ptr;
		ptr = ptr->next;
		i++;
	}
	i = 0;
	ptr = *stack_a;
	while (ptr != min)
	{
		ptr = ptr->next;
		i++;
	}
	while (*stack_a != min)
	{
		if (i <= 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	(*stack_a)->len--;
}