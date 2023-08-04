/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:05:59 by svikornv          #+#    #+#             */
/*   Updated: 2023/08/04 17:20:00 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_vars	v;
	int	i;
	int	j;

	stack_a = init_stack();
	i = 0;
	v.characters = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i + 1][j])
		{
			if ((argv[i + 1][j] != ' ') && argv[i + 1][j] != '\t')
				v.characters++;
			if (argv[i + 1][j] == '\t')
				argv[i + 1][j] = ' ';
			j++;
		}
		if (v.characters == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		v.characters = 0;
		get_val(&stack_a, argv[i + 1]);
		i++;
	}
	check_dup(stack_a);
	check_sort(stack_a);
	stack_b = init_stack();
	push_swap(&stack_a, &stack_b);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->next = NULL;
	stack->len = 0;
	stack->max_num = 0;
	return (stack);
}

void	get_val(t_stack **stack_a, char *arg)
{
	char	**arg_split;
	int		i;
	long		num;

	arg_split = ft_split(arg, ' ');
	i = 0;
	while (arg_split[i])
	{
		num = ft_atoi(arg_split[i]);
		if (num > (*stack_a)->max_num)
			(*stack_a)->max_num = num;
		num_to_stack(stack_a, num);
		ft_error(num, arg_split[i], *stack_a);
		free(arg_split[i]);
		i++;
	}
	free(arg_split);
}

t_stack	*ft_newnode(int num)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = num;
	new->indx = 0;
	new->next = NULL;
	return (new);
}

void	num_to_stack(t_stack **stack_a, int num)
{
	t_stack	*new_node;
	t_stack	*ptr;

	new_node = ft_newnode(num);
	if ((*stack_a)->len == 0)
	{
		free(*stack_a);
		*stack_a = NULL;
		*stack_a = new_node;
		(*stack_a)->len++;
		return ;
	}
	ptr = *stack_a;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_node;
	(*stack_a)->len++;
}
