/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:30 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/06 15:16:51 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Shifts up all elements of stack a by 1.
//	The first element becomes the last one.

void	rot_a(t_list **stackA)
{
	t_list	*first;
	t_list	*last;

	if (!stackA || !*stackA || !(*stackA)->next)
		return ;
	first = *stackA;
	*stackA = first->next; // Move head to second node
	last = *stackA;
	while (last->next) // Find the last node
		last = last->next;
	last->next = first; // Link last to first
	first->next = NULL;
}

//	Shifts up all elements of stack a by 1.
//	The first element becomes the last one.

void	rot_b(t_list **stackB)
{
	t_list	*first;
	t_list	*last;

	if (!stackB || !*stackB || !(*stackB)->next)
		return ;
	first = *stackB;
	*stackB = first->next;
	last = *stackB;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

// Shifts(rotates) ra & rb at the same time

void	rot_ab(t_list **stackA, t_list **stackB)
{
	t_list	*first;
	t_list	*last;
	t_list	*first;
	t_list	*last;

	if (stackA && *stackA && (*stackA)->next)
	{
		first = *stackA;
		*stackA = first->next;
		last = *stackA;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	if (stackB && *stackB && (*stackB)->next)
	{
		first = *stackB;
		*stackB = first->next;
		last = *stackB;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}
