/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/15 16:47:46 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// This function is to sort 2,3,4 or 5 numbers using simple move like (sa,ra,rra) etc.

void	sort_small(t_list **stackA, int size)
{
	if (size < 2 || *stackA == NULL || (*stackA)->next == NULL)
		return ;

	t_list	*first = *stackA;
	t_list	*second = first->next;

	first = *stackA;
	second = first->next;
	if (first->data > second->data)
		swap_a(stackA);
}

// void	sort_large(void)
// {
// }

// void	sort_stack(void)
// {
// }