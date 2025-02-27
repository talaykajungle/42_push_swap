/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/27 17:29:31 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	minimum(t_list *stackA)
{
	int		min;
	t_list	*stacknow;

	if (!stackA)
		return (0);
	min = stackA->data;
	stacknow = stackA->next;
	while (stacknow)
	{
		if (stacknow->data < min)
			min = stacknow->data;
		stacknow = stacknow->next;
	}
	return (min);
}

void	put_to_top(t_list **stackA, int index, int size)
{
	if (index <= size / 2)
	{
		while (index-- > 0)
			rot_a(stackA);
	}
	else
	{
		while (index++ < size)
		{
			rev_rot_a(stackA);
		}
	}
}

void	sort3(t_list **stackA)
{
	if (sorted(*stackA))
		return;
	if (minimum(*stackA) == 0)
	{
		swap_a(stackA);
		rot_a(stackA);
	}
	else if (minimum(*stackA) == 1)
	{
		if ((*stackA)->data < (*stackA)->next->next->data)
			swap_a(stackA);
		else
			rot_a(stackA);
	}
	else
	{
		if ((*stackA)->data < (*stackA)->next->data)
			rev_rot_a(stackA);
		else
			swap_a(stackA);
		rev_rot_a(stackA);
	}
}

void	sort4(t_list **stackA, t_list **stackB)
{
	put_to_top(stackA, minimum(*stackA), 4);
	if (sorted(*stackA))
		return ;
	push_b(stackA, stackB);
	sort3(stackA);
	push_a(stackA, stackB);
}

void	sort5(t_list **stackA, t_list **stackB)
{
	put_to_top(stackA, minimum(*stackA), 5);
	if (sorted(*stackA))
		return ;
	push_b(stackA, stackB);
	sort4(stackA, stackB);
	push_a(stackA, stackB);
}
