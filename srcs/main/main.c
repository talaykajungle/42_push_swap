/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/22 21:43:44 by codespace        ###   ########.fr       */
=======
/*   Updated: 2025/03/21 15:53:54 by tamutlu          ###   ########.fr       */
>>>>>>> 95b655a505abce0183dfc65b09db94d51ec6b342
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

int	main(int argc, char **argv)
{
	if(argc != 4)
	{
		return 0;
	}
	printf("Test Case 1: Unsorted 2 elements\n");
	test_sort_small(ft_atoi(argv[1]),ft_atoi(argv[2]), ft_atoi(argv[3])); // Should sort to 1, 2, 0
	return (0);
}