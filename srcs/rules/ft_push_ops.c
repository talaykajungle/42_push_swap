/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talaykajungle <talaykajungle@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:27 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/21 19:01:04 by talaykajung      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	push(t_list **stackA, t_list **stackB)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stackB) == 0)
		return (-1);
	head_to = *stackA;
	head_from = *stackB;
	tmp = head_from;
	head_from = head_from->next;
	*stackB = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stackA = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stackA = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
