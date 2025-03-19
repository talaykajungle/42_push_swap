/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/19 22:54:31 by tamutlu          ###   ########.fr       */
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

void	test_sort_small(int a, int b, int c)
{
	t_list	*stackA;

	stackA = create_node(a);
	stackA->next = create_node(b);
	stackA->next->next = create_node(c);
	printf("Before sorting:\n");
	print_list(stackA);
	sort_small(&stackA, 3);
	printf("After sorting:\n");
	print_list(stackA);
	free_list(stackA);
}

int	main(void)
{
	printf("Test Case 1: Unsorted 2 elements\n");
	test_sort_small(2, 1, 0); // Should sort to 1, 2, 0

	printf("\nTest Case 2: Sorted 2 elements\n");
	test_sort_small(1, 2, 0); // Should remain 1, 2, 0

	printf("\nTest Case 3: Unsorted 3 elements\n");
	test_sort_small(3, 1, 2); // Should sort to 1, 2, 3

	printf("\nTest Case 4: Already sorted 3 elements\n");
	test_sort_small(1, 2, 3); // Should remain 1, 2, 3

	printf("\nTest Case 5: Reverse sorted 3 elements\n");
	test_sort_small(3, 2, 1); // Should sort to 1, 2, 3

	printf("\nTest Case 6: All elements the same\n");
	test_sort_small(1, 1, 1); // Should remain 1, 1, 1
	return (0);
}