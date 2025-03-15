/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/15 16:20:51 by tamutlu          ###   ########.fr       */
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

// Free the list
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

// void	test_sort_small(int num1, int num2)
// {
// 	t_list	*stackA;

// 	stackA = create_node(num1);
// 	stackA->next = create_node(num2);
// 	assign_indices(&stackA, 2);
// 	printf("Before sorting:\n");
// 	print_list(stackA);
// 	sort_small(&stackA, 2);
// 	printf("After sorting:\n");
// 	print_list(stackA);
// 	free_list(stackA);
// }

int	main(void)
{
	t_list *stackA = NULL;
		// Assuming create_node allocates a node with data 5
	//stackA->next = create_node(3);   // Second node with data 3
	int size = 2;                    // Number of elements in the stack

	// Call sort_small with the correct arguments
	sort_small(&stackA, size); // Pass the address of stackA and the size

	// Optional: Print the list after sorting
	printf("After sorting:\n");
	print_list(stackA);

	// Clean up memory
	free_list(stackA); // Assuming free_list is defined to free the list

	return (0);
}