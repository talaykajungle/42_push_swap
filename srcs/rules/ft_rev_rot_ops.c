/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rot_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:32 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/20 17:03:56 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_a(t_list **stackA)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stackA;
	if (!*stackA || !(*stackA)->next)
		return ;
	while (!tmp)
	{
		tmp = tmp->next;
	}
	tmp->next = *stackA;
	last->next = stackA;
	*stackA = last;
	write(1, "rra\n", 4);
}

void	rev_rot_b(t_list **stackB)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stackB;
	if (!*stackB || !(*stackB)->next)
		return ;
	while (!tmp)
	{
		tmp = tmp->next;
	}
	tmp->next = *stackB;
	last->next = stackB;
	*stackB = last;
	write(1, "rrb\n", 4);
}

void	rev_rot_ab(t_list **stackA, t_list **stackB)
{
	rev_rot_a(stackA);
	rev_rot_b(stackB);
}