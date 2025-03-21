/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:30 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/21 16:34:53 by tamutlu          ###   ########.fr       */
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
	*stackA = first->next;
	last = *stackA;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd("ra", 1);
	return(0);
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
	write(1, "rb\n", 3);
}

// Shifts(rotates) ra & rb at the same time

void	rot_ab(t_list **stackA, t_list **stackB)
{
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
