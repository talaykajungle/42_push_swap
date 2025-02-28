/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:30 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/28 17:30:56 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Shifts up all elements of stack a by 1.
//	The first element becomes the last one.

void	rot_a(t_list **stackA)
{
	t_list	*tmp;

	tmp = *stackA;
	if (!*stackA || !(*stackA)->next)
		return ;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *stackA;
	*stackA = (*stackA)->next;
	write(1, "ra\n", 3);
}

//	Shifts up all elements of stack a by 1.
//	The first element becomes the last one.

void	rot_b(t_list **stackB)
{
	t_list	*tmp;

	tmp = *stackB;
	if (!*stackB || !(*stackB)->next)
		return ;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *stackB;
	*stackB = (*stackB)->next;
	write(1, "rb\n", 3);
}

// Shifts(rotates) ra & rb at the same time

void	rot_ab(t_list **stackA, t_list **stackB)
{
	rot_a(stackA);
	rot_b(stackB);
	write(1, "rr\n", 3);
}
