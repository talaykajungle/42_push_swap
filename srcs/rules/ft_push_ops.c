/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:27 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/06 14:26:06 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Takes the first element at the top of stack b
//	and places it at the top of stack a

void	push_a(t_list **stackA, t_list **stackB)
{
	t_list	*head;

	if (!*stackB)
		return ;
	head = *stackB;
	*stackB = (*stackB)->next;
	head->next = *stackA;
	*stackA = head;
}

//	Takes the first element at the top of stack a
//	and places it at the top of stack b

void	push_b(t_list **stackA, t_list **stackB)
{
	t_list	*head;

	if (!*stackA)
		return ;
	head = *stackA;
	*stackA = (*stackA)->next;
	head->next = *stackB;
	*stackB = head;
}

// void	push_ab(t_list **stackA, t_list **stackB)
// {
// 	push_a(*stackA, *stackB);
// 	push_b(*stackA, *stackB);
// }
