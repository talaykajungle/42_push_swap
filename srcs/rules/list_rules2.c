/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talaykajungle <talaykajungle@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:01:57 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/21 19:42:29 by talaykajung      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Prints the linked list
int	printlist(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->data, 2);
		ft_putendl_fd("", 2);
		tmp = tmp->next;
	}
	return (0);
}

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
	int	size;
	t_list	*stackB;
	
	size = ft_lstsize(*stackA);
	stackB = NULL;
	assign_indices(stackA, size);
	if (size <= 5)
		simple_sort(stackA);
	else
	{
		ft_putstr_fd("sort_stack: calling radix\n", 2);
		radix(stackA, &stackB);
	}
}
