/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rot_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:32 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/12 22:11:48 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Shifts down all elements of stack a by 1

int	reverse(t_list **stackA)
{
	t_list	*head;
	t_list	*tail;

	// Calls to count the number of node in a list
	if (ft_lstsize(*stackA) < 2)
		return (-1);
	// Sets "head" to point to first node of the list
	head = *stackA;
	tail = ft_lstlast(head);
	//	Traverses the list to find the second-to-last-node
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	//	Sets the next pointer to the last node (tail) to current head list
	tail->next = *stackA;
	*stackA = tail;
	return (0);
	// Indicates the rotation was successful
}

int	rra(t_list **stackA)
{
	if (reverse(stackA) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}
int	rrb(t_list **stackB)
{
	if (reverse(stackB) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}
int	rrr(t_list **stackA, t_list **stackB)
{
	if ((ft_lstsize(*stackA) < 2) || (ft_lstsize(*stackB) < 2))
		return (-1);
	reverse(stackA);
	reverse(*stackB);
	ft_putendl_fd("rrr", 1);
	return (0);
}