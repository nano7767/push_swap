/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:23:18 by svikornv          #+#    #+#             */
/*   Updated: 2023/08/04 17:29:21 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(long num, char *arg_split, t_stack *stack_a)
{
	int	i;
	i = 0;
	while (arg_split[i])
	{
		if (arg_split[i] == '\t' || arg_split[i] == '\n' || arg_split[i] == '\v'
			|| arg_split[i] == '\f' || arg_split[i] == '\r' || arg_split[i] == ' ')
			i++;
		if (arg_split[i] != '+' && arg_split[i] != '-')
		{
			if (arg_split[i + 1] == '+' || arg_split[i + 1] == '-')
				err_exit(stack_a);
		}
		if (!ft_isdigit(arg_split[i]))
			err_exit(stack_a);
		i++;
	}
	if (num == 0 && arg_split[0] != '0')
		err_exit(stack_a);
	if ((num > 2147483647 || num < -2147483648))
		err_exit(stack_a);
}

void	check_dup(t_stack *stack_a)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = stack_a;
	while (ptr)
	{
		ptr2 = ptr->next;
		while (ptr2)
		{
			if (ptr->data == ptr2->data)
				err_exit(stack_a);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

void	check_sort(t_stack *stack_a)
{
	t_stack	*ptr;

	ptr = stack_a;
	while (ptr->next)
	{
		if (ptr->data < ptr->next->data)
			ptr = ptr->next;
		else
			return ;
	}
	free_stack(stack_a);
	stack_a = NULL;
	exit(0);
}

void	err_exit(t_stack *stack)
{
	free_stack(stack);
	stack = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = stack;
	while (stack)
	{
		ptr2 = ptr->next;
		stack = (stack)->next;
		free(ptr);
		ptr = ptr2;
	}
}
