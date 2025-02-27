/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:27 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/27 17:26:14 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Takes the first element at the top of stack b
//	and places it at the top of stack a

void	push_a(t_list **stackA, t_list **stackB)
{
	t_list	*head;

	if (*stackB)
	{
		head = (*stackB)->next;
		*stackA = *stackB;
		*stackB = head;
		write(1, "pa\n", 3);
	}
}

//	Takes the first element at the top of stack a
//	and places it at the top of stack b

void	push_b(t_list **stackA, t_list **stackB)
{
	t_list	*head;

	if (*stackA)
	{
		head = (*stackA)->next;
		*stackB = *stackA;
		*stackA = head;
		write(1, "pb\n", 3);
	}
}

// void	push_ab(t_list **stackA, t_list **stackB)
// {
// 	push_a(*stackA, *stackB);
// 	push_b(*stackA, *stackB);
// }
