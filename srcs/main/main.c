/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/04 17:29:08 by tamutlu          ###   ########.fr       */
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
		{
			tmp = tmp->next;
			tmp->next = new_node;
		}
	}
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

// int	main(int argc, char *argv[])
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	int		i;
// 	t_list	*temp;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (argc < 2 || !is_valid_input(argc, argv))
// 	{
// 		ft_printf("Error: Invalid input\n");
// 		return (1);
// 	}
// 	i = 1;
// 	while (i < argc)
// 	{
// 		add_to_stack(&stack_a, ft_atoi(argv[i]));
// 		i++;
// 	}
// 	if (argc - 1 == 3)
// 		sort3(&stack_a);
// 	else if (argc - 1 == 4)
// 		sort4(&stack_a, &stack_b);
// 	else if (argc - 1 == 5)
// 		sort5(&stack_a, &stack_b);
// 	else
// 		ft_printf("Sorting not implemented for %d elements\n", argc - 1);
// 	while (stack_a)
// 	{
// 		temp = stack_a;
// 		stack_a = stack_a->next;
// 		free(temp);
// 	}
// 	while (stack_b)
// 	{
// 		temp = stack_b;
// 		stack_b = stack_b->next;
// 	}
// 	return (0);
// }

void	load_stack_from_split(t_list **stack_a, char *arg)
{
	char	**split_args;
	int		i;

	split_args = ft_split(arg, ' ');
	i = 0;
	if (!split_args || !is_valid_input(split_args))
	{
		ft_free_split(split_args);
		ft_printf("Error: Invalid input\n");
		exit(1);
	}
	while (split_args[i])
	{
		add_to_stack(stack_a, ft_atoi(split_args[i]));
		i++;
	}
	ft_free_split(split_args);
}

int	main(int argc, char *argv[])
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int i = 1;
	t_list *temp;
	if (argc < 2)
	{
		ft_printf("Error: Invalid input\n");
		return (1);
	}
	if (argc == 2)
		load_stack_from_split(&stack_a, argv[1]);
	else if (!is_valid_input(argc, argv))
	{
		ft_printf("Error: Invalid input\n");
		return (1);
	}
	else
		while (i < argc)
			add_to_stack(&stack_a, ft_atoi(argv[i++]));
	// Sorting and freeing logic as before
}