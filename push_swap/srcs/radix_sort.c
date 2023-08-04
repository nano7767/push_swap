/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:30:09 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/26 16:36:23 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits(t_stack *stack_a)
{
	int	count;
	int	max_num;

	count = 0;
	max_num = stack_a->len;
	while (max_num != 0)
	{
		max_num >>= 1;
		count++;
	}
	return (count);
}
// int	get_bits(t_stack *stack_a)
// {
// 	int	count;
// 	int	max_num;

// 	count = 0;
// 	max_num = stack_a->max_num;
// 	while (max_num != 0)
// 	{
// 		max_num >>= 1;
// 		count++;
// 	}
// 	return (count);
// }

// int	check_sort(t_stack **stack_a)
// {
// 	t_stack	*ptr;

// 	ptr = *stack_a;
// 	while (ptr->next)
// 	{
// 		if (ptr->data < ptr->next->data)
// 			ptr = ptr->next;
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	max_bits;
	int	lstlen;
	int	lstlen2;

	max_bits = get_bits(*stack_a);
	lstlen = (*stack_a)->len;
	lstlen2 = 0;
	i = 0;
	while (i < max_bits /*&& check_sort(stack_a)*/)
	{
		j = 0;
		while (j < lstlen)
		{
			if (((*stack_a)->indx >> i) & 1)
			{
				ra(stack_a);
			}
			else
			{
				pb(stack_a, stack_b);
				lstlen2++;
			}
			j++;
		}
		while (lstlen2)
		{
			pa(stack_a, stack_b);
			lstlen2--;
		}
		i++;
		//printf("round %d\n", i + 1);
	}
}

// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	i;
// 	int	j;
// 	int	max_bits;
// 	int	lstlen;
// 	int	lstlen2;

// 	max_bits = get_bits(*stack_a);
// 	lstlen = (*stack_a)->len;
// 	lstlen2 = 0;
// 	i = 0;
// 	while (i < max_bits /*&& check_sort(stack_a)*/)
// 	{
// 		j = 0;
// 		while (j < lstlen)
// 		{
// 			if (((*stack_a)->data >> i) & 1)
// 			{
// 				ra(stack_a);
// 			}
// 			else
// 			{
// 				pb(stack_a, stack_b);
// 				lstlen2++;
// 			}
// 			j++;
// 		}
// 		while (lstlen2)
// 		{
// 			pa(stack_a, stack_b);
// 			lstlen2--;
// 		}
// 		i++;
// 		//printf("round %d\n", i + 1);
// 	}
// }

// void	radix_sort(t_stack **stack_a)
// {
// 	int	i;
// 	int	j;
// 	t_stack	*ptr;
// 	t_stack	*buckets[10];
// 	int	bucket_indx;
// 	int	divisor;
// 	t_stack	*next_node;

// 	i = 0;
// 	divisor = 1;
// 	while (i < (*stack_a)->max_digits)
// 	{
// 		j = 0;
// 		while (j < 10)
// 			buckets[j++] = NULL;
// 		ptr = *stack_a;
// 		while (ptr)
// 		{
// 			bucket_indx = ((ptr->data) / divisor) % 10;
// 			next_node = ptr->next;
// 			ptr->next = buckets[bucket_indx];
// 			buckets[bucket_indx] = ptr;
// 			ptr = next_node;
// 		}
// 		*stack_a = NULL;
// 		j = 9;
// 		while (j >=0)
// 		{
// 			ptr = buckets[j];
// 			while (ptr)
// 				pa(stack_a, &ptr);
// 			j--;
// 		}
// 		i++;
// 		divisor *= 10;
// 	}
// }