/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:01:57 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/18 22:05:45 by tamutlu          ###   ########.fr       */
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

	// t_list	*stackB;
	size = ft_lstsize(*stackA);
	ft_putstr_fd("sort_stack: size = ", 2);
	ft_putnbr_fd(size, 2);
	ft_putendl_fd("", 2);
	if (size <= 5)
		simple_sort(stackA);
	// else
	// {
	// 	ft_putstr_fd("sort_stack: calling radix_sort\n", 2);
	// 	radix_sort(stackA);
	// }
	// ft_putstr_fd("sort_stack: final stack = ", 2);
	// print_list(*stackA);
}
