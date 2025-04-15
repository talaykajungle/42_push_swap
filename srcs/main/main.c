/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:33 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/15 20:56:10 by tamutlu          ###   ########.fr       */
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
void	free_list(t_list *head)
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
}

static void	sort_stack(t_list **stackA)
{
	if (ft_lstsize(*stackA) <= 5)
		simple_sort(stackA);
}

int	main(int argc, char **argv)
{
	t_list	**stackA;
	t_list	**stackB;

	if (argc < 2)
	{
		return (0);
	}
	stackA = (t_list **)malloc(sizeof(t_list));
	stackB = (t_list **)malloc(sizeof(t_list));
	*stackA = NULL;
	*stackB = NULL;
	build_stack(**stackA, argc);
	if(is_sorted(*stackA))
	{
		free_list(*stackA);
		free_list(*stackB);
	}
	
	sort_stack(0);
	// Should sort to 1, 2, 0
	return (0);
}
