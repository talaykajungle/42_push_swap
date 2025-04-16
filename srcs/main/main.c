/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:33 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/16 23:38:54 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*create_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->data = data;
		node->index = 0;
		node->next = NULL;
	}
	return (node);
}

// Print the list
void	print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("Data: %d, Index: %d\n", temp->data, temp->index);
		temp = temp->next;
	}
}

// // Free the list
void	free_list(t_list *head, t_list *head2)
{
	t_list	*current;
	t_list	*temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	if (head2 == NULL)
		return ;
	current = head2;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	sort_stack(t_list **stackA)
{
	if (ft_lstsize(*stackA) <= 5)
		simple_sort(stackA);
	// else
	// 	radix();
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	if (argc < 2)
		return (0);
	stacka = NULL;
	stackb = NULL;
	stacka = build_stack(argv + 1, argc - 1);
	if (!stacka)
	{
		ft_putstr_fd("Error\n", 2);
		return (free_list(stacka, stackb), 1);
	}
	if (is_sorted(&stacka))
	{
		return (free_list(stacka, stackb), 0);
	}
	sort_stack(&stacka);
	free_list(stacka, stackb);
	return (0);
}
