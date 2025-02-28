/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/28 16:40:04 by tamutlu          ###   ########.fr       */
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
		return;
	new_node = create_node(data);
	if (!new_node)
		return ;
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

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	t_list	*temp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_printf("Usage: %s <numbers>\n", argv[0]);
		return (1);
	}
	for (i = argc - 1; i > 0; i--)
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
	// Free stack_a using a while loop
	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	// Free stack_b using a while loop
	while (stack_b)
	{
		temp = stack_b;
		stack_b = stack_b->next;
		free(temp);
	}
	return (0);
}
//cc ./srcs/header/push_swap.h ./srcs/rules/*.c ./srcs/sorts/*.c ./srcs/main/main.c 