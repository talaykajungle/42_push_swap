/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/24 19:05:16 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum(t_list *stackA)
{
	int		min;
	t_list	*stacknow;

	if (!stackA)
		return (0);
	min = stackA->data;
	stacknow = stackA->next;
	while (stackA)
	{
		if (stacknow->data < min)
			min = stacknow->data;
		stacknow = stacknow->next;
	}
	reuturn(min);
}

void	sort3(t_list **stackA)
{
	if (sorting(*stackA))
		return (0);
	if (minimum(*stackA) == 0)
	{
		swap_a(stackA);
		rot_a(stackA);
	}
	else if (minimum(*stackA) == 1)
	{
		if ((*stackA)->data < (*stackA)->next->next->data)
			swap_a(*stackA);
		else
			rot_a(*stackA);
	}
	else
	{
		if ((*stackA)->data < (*stackA)->next->data)
			rev_rot_a(*stackA);
		else
			swap_a(*stackA);
			rev_rot_a(*stackA);
	}
}

void	sort5(t_list **stackA, t_list **stackB)
{
	
}
