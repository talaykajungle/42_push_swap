/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rot_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:32 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/01 14:26:24 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Shifts down all elements of stack a by 1

void	rev_rot_a(t_list **stackA)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stackA;
	if (!*stackA || !(*stackA)->next)
		return ;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stackA;
	*stackA = last;
	write(1, "rra\n", 4);
}

//	Shifts down all elements of stack b by 1

void	rev_rot_b(t_list **stackB)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stackB;
	if (!*stackB || !(*stackB)->next)
		return ;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stackB;
	*stackB = last;
	write(1, "rrb\n", 4);
}

// Reverse rotates both stacks

void	rev_rot_ab(t_list **stackA, t_list **stackB)
{
	rev_rot_a(stackA);
	rev_rot_b(stackB);
	write(1, "rrr\n", 4);
}
