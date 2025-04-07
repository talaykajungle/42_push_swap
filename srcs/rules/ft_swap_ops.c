/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:00:29 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/07 18:39:54 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Swaps the first 2 elements at the top of the stack a
int	swap(t_list **stackA)
{
	t_list_libft	*head;
	t_list_libft	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize((*stackA) < 2))
		return (-1);
	head = *stackA;
	next = head->next;
	tmp_val = head->data;
	tmp_index = head->index;
	head->data = next->data;
	head->index = next->index;
	next->data = tmp_val;
	next->index = tmp_index;
	return (0);
}
int	sa(t_list **stackA)
{
	if (swap(stackA) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}
int	sb(t_list **stackB)
{
	if (swap(stackB) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}
int	ss(t_list **stackA, t_list **stackB)
{
	if ((ft_lstsize(*stackA) < 2) || (ft_lstsize(*stackB) < 2))
		return (-1);
	swap(stackA);
	swap(stackB);
	ft_putendl_fd("ss", 1);
	return (0);
}
