/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:30:09 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/13 14:07:39 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*ptr;
// 	t_stack	*buckets[10];
// 	t_stack	*tmp;
// 	int	i;
// 	int	j;
// 	int	bucket_indx;

// 	ptr = *stack_a;
// 	i = 0;
// 	while (i < (*stack_a)->max_digits)
// 	{
// 		while (ptr)
// 		{
// 			bucket_indx = get_digit(ptr->data, i);
// 			tmp = ptr;
// 			ptr = ptr->next;
// 			tmp->next = buckets[bucket_indx];
// 			buckets[bucket_indx] = tmp;
// 		}
// 		*stack_a = NULL;
// 		j = 9;
// 		while (j--)
// 		{
// 			if (buckets[j] != NULL)
// 			{
// 				buckets[j]->next = *stack_a;
// 				*stack_a = buckets[j];
// 			}
// 		}
// 		ptr = *stack_a;
// 		i++;
// 	}
// }

// int get_digit(int num, int digit)
// {
// 	int	divisor;
// 	int	i;

// 	divisor = 1;
// 	i = 0;
// 	while (i < digit)
// 	{
// 		divisor *= 10;
// 		i++;
// 	}
// 	return (num / divisor) % 10;
// }

void	radix_sort(t_stack **stack_a)
{
	int	i;
	int	j;
	t_stack	*ptr;
	t_stack	*buckets[10];
	int	bucket_indx;
	int	divisor;
	t_stack	*next_node;

	i = 0;
	divisor = 1;
	while (i < (*stack_a)->max_digits)
	{
		j = 0;
		while (j < 10)
			buckets[j++] = NULL;
		ptr = *stack_a;
		while (ptr)
		{
			bucket_indx = (*(ptr->data) / divisor) % 10;
			next_node = ptr->next;
			ptr->next = buckets[bucket_indx];
			buckets[bucket_indx] = ptr;
			ptr = next_node;
		}
		*stack_a = NULL;
		j = 0;
		while (j < 10)
		{
			ptr = buckets[j];
			while (ptr)
			{
				pa(stack_a, &ptr);
				ptr = ptr->next;
			}
			j++;
		}
		divisor *= 10;
	}
}