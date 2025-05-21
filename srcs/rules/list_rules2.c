/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:01:57 by tamutlu           #+#    #+#             */
/*   Updated: 2025/05/21 16:42:44 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	int		size;
	t_list	*stackb;

	size = ft_lstsize(*stackA);
	stackb = NULL;
	assign_indices(stackA, size);
	if (size <= 5)
		simple_sort(stackA);
	else
		radix(stackA, &stackb);
}
