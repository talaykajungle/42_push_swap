/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/05 11:42:49 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*create_node(int data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_stack(t_list **stack, int data)
{
	t_list	*new_node;
	t_list	*tmp;

	if (!stack)
		return ;
	new_node = create_node(data);
	if (!new_node)
	{
		free_list(stack);
		ft_printf("Error: Memory allocation failed\n");
		exit(1);
	}
	if (!*stack)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	while (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	while (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
	}
}

int	is_valid_input(int argc, char *argv[])
{
	long	num;
	char	*str;

	int i, j;
	for (i = 1; i < argc; i++)
	{
		str = argv[i];
		if (*str == '-' || *str == '+')
			str++;
		if (!*str)
			return (0);
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (0);
			str++;
		}
		num = atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		for (j = i + 1; j < argc; j++)
			if (atol(argv[j]) == num)
				return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ft_printf("Error: Invalid input\n"), 1);
	count = load_stack(&stack_a, argc, argv);
	if (!count)
		return (ft_printf("Error: Invalid input\n"), 1);
	sort_stack(&stack_a, &stack_b, count);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
