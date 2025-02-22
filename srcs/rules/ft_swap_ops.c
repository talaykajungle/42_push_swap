/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:35 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/22 15:18:47 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

//	Swaps the first 2 elements of both stack at the same time

void	swap_ab(t_list **stackA, t_list **stackB)
{
	swap_a(stackA);
	swap_b(stackB);
	write(1, "ss\n", 3);
}
