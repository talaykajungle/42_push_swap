/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:27 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/19 16:51:34 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_ab(t_list **stackA, t_list **stackB)
{
	push_a(*stackA, *stackB);
	push_b(*stackA, *stackB);
}