/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rot_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:32 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/22 16:36:20 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	reverse(t_list **stackA)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stackA) < 2)
		return (-1);
	head = *stackA;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stackA;
	*stackA = tail;
	return (0);
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
	reverse(stackB);
	ft_putendl_fd("rrr", 1);
	return (0);
}
