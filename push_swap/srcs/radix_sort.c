/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:30:09 by svikornv          #+#    #+#             */
/*   Updated: 2023/08/04 17:27:16 by svikornv         ###   ########.fr       */
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
	while (i < max_bits)
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
	}
}
