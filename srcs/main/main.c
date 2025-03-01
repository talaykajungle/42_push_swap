/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/01 15:32:16 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d \n", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

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

	if (!stack)
		return ;
	new_node = create_node(data);
	if (!new_node)
	{
		free_list(stack);
		ft_printf("Error: Memory allocation failed\n");
		exit(1);
	}
	new_node->next = *stack;
	*stack = new_node;
}

void	free_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
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
	int		i;
	t_list	*temp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !is_valid_input(argc, argv))
	{
		ft_printf("Error: Invalid input\n");
		return (1);
	}
	for (i = 1; i < argc; i++)
		add_to_stack(&stack_a, ft_atoi(argv[i]));
	printf("Initial stack A: ");
	print_stack(stack_a);
	if (argc - 1 == 3)
		sort3(&stack_a);
	else if (argc - 1 == 4)
		sort4(&stack_a, &stack_b);
	else if (argc - 1 == 5)
		sort5(&stack_a, &stack_b);
	else
		ft_printf("Sorting not implemented for %d elements\n", argc - 1);
	ft_printf("Sorted stack A: ");
	print_stack(stack_a);
	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	while (stack_b)
	{
		temp = stack_b;
		stack_b = stack_b->next;
		free(temp);
	}
	return (0);
}
// cc ./srcs/header/push_swap.h ./srcs/rules/*.c ./srcs/sorts/*.c ./srcs/main/main.c