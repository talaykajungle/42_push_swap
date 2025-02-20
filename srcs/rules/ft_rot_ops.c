/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:30 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/20 14:20:44 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_list **stackA, int i)
{
	t_list	*tmp;

	tmp = *stackA;
	if (!*stackA || !(*stackA)->next)
		return ;
	while (!tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *stackA;
	*stackA = (*stackA)->next;
	write(1,"ra\n", 3);
}

void	rot_b(t_list **stackB, int i)
{
	t_list	*tmp;

	tmp = *stackB;
	if (!*stackB || !(*stackB)->next)
		return ;
	while (!tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *stackB;
	*stackB = (*stackB)->next;
	write(1,"rb\n", 3);
}

void	rot_ab(t_list **stackA, t_list **stackB)
{
	rot_a(stackA, NULL);
	rot_b(stackB, NULL);
	write(1,"rr\n", 3);
}