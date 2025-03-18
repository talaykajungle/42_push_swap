/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:46 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/18 17:00:06 by tamutlu          ###   ########.fr       */
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

void	test_sort_small(int num1, int num2)
{
	t_list	*stackA;

	stackA = create_node(num1);
	stackA->next = create_node(num2);
	assign_indices(&stackA, 2);
	printf("Before sorting:\n");
	print_list(stackA);
	sort_small(&stackA, 2);
	printf("After sorting:\n");
	print_list(stackA);
	free_list(stackA);
}

int main(int argc, char **argv)
{
    t_list *stackA = NULL;
    t_list *stackB = NULL;
    int size;

    if (argc < 2)
        return (write(2, "Error\n", 6), 1);

    size = argc - 1;
    stackA = build_stack(argv + 1, size);
    if (!stackA)
        return (write(2, "Error\n", 6), 1);

    assign_indices(&stackA, size);
    if (size <= 5)
        sort_small(&stackA, &stackB);
    // else
    //     sort_large(&stackA, &stackB, size);

    free_list(stackA);
    free_list(stackB);
    return (0);
}