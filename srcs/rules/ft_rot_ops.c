/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:30 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/07 15:58:40 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Shifts up all elements of stack a by 1.
//	The first element becomes the last one.

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*end;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	end = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	end->next = head;
	return (0);
}

int	ra(t_list **stackA)
{
	if (rotate(stackA) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **stackB)
{
	if (rotate(stackB) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **stackA, t_list **stackB)
{
	if ((ft_lstsize(*stackA) < 2) || (ft_lstsize(*stackB) < 2))
		return (-1);
	rotate(stackA);
	rotate(stackB);
	ft_putendl_fd("rr", 1);
	return (0);
}
