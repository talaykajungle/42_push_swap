/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:35 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/06 15:18:55 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Swaps the first 2 elements at the top of the stack a

void	swap_a(t_list **stackA)
{
	t_list	*first;
	t_list	*second;

	first = *stackA;
	second = first->next;
	if (!stackA || !*stackA || !(*stackA)->next)
		return ;
	first->next = second->next;
	second->next = first;
	*stackA = second;
}

//	Swaps the first 2 elements at the top of the stack b

void	swap_b(t_list **stackB)
{
	t_list	*first;
	t_list	*second;

	first = *stackB;
	second = first->next;
	if (!stackB || !*stackB || !(*stackB)->next)
		return ;
	first->next = second->next;
	second->next = first;
	*stackB = second;
}

//	Swaps the first 2 elements of both stack at the same time

void	swap_ab(t_list **stackA, t_list **stackB)
{
	t_list	*first;
	t_list	*second;
	t_list	*first;
	t_list	*second;

	if (stackA && *stackA && (*stackA)->next)
	{
		first = *stackA;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stackA = second;
	}
	if (stackB && *stackB && (*stackB)->next)
	{
		first = *stackB;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stackB = second;
	}
}
