/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:05:59 by svikornv          #+#    #+#             */
/*   Updated: 2023/07/16 12:08:56 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;
	int	num;

	if (argc == 1)
	{
		printf("empty parameter");
		return (1);
	}
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (1);
	stack_a->next = NULL;
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (1);
	stack_b->next = NULL;
	i = 0;
	stack_a->len = 0;
	while (i < argc - 1)
	{
		num = ft_atoi(argv[i + 1]);
		num_to_stack(&stack_a, num);
		get_max_digits(stack_a, num);
		i++;
	}
	push_swap(&stack_a, &stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

void	get_max_digits(t_stack *stack_a, int num)
{
	int	digits;

	digits = 0;
	while (num != 0)
	{
		digits++;
		num /= 10;
	}
	if (digits > stack_a->max_digits)
		stack_a->max_digits = digits;
}

void	num_to_stack(t_stack **stack_a, int num)
{
	t_stack	*new_node;
	t_stack	*ptr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = num;
	if ((*stack_a)->len == 0)
	{
		*stack_a = new_node;
		(*stack_a)->len++;
		return ;
	}
	ptr = ft_stacklast(*stack_a);
	ptr->next = new_node;
	(*stack_a)->len++;
}

t_stack	*ft_stacklast(t_stack *stack_a)
{
	t_stack	*ptr;
	// t_stack	*ptr2;
	// int		count;

	if (!stack_a)
		return (NULL);
	ptr = stack_a;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
	// if (stack_a == NULL)
	// 	return (NULL);
	// ptr = stack_a;
	// count = 0;
	// while (ptr != NULL)
	// {
	// 	ptr = ptr -> next;
	// 	count++;
	// }
	// ptr2 = stack_a;
	// while (count > 1)
	// {
	// 	ptr2 = ptr2 -> next;
	// 	count--;
	// }
	// return (ptr2);

// void	ft_stackdelone(t_stack *stack_a, void (*del)(void *))
// {
// 	if (stack_a == NULL || del == NULL)
// 		return ;
// 	del(stack_a->data);
// 	free(lst);
// }