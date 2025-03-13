/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:47 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/13 16:53:12 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Assign indices to stackA based on how many numbers are smaller than its data

void	assign_indices(t_list **stackA, int size)
{
	t_list	*current;
	t_list	*checker;
	int		count;

	if (!*stackA || size <= 1)
	{
		if (*stackA)
			(*stackA)->index = 0;
		return ;
	}
	current = *stackA;
	while (current != NULL)
	{
		count = 0;
		checker = *stackA;
		while (checker != NULL)
		{
			if (checker->data < current->data)
				count++;
			checker = checker->next;
		}
		current->index = count;
		current = current->next;
	}
}

// This function is to sort 2,3,4 or 5 numbers using simple move like (sa,ra,rra) etc.

void	sort_small(t_list **stackA, t_list **stackB, int size)
{
	
}

// void	sort_large(void)
// {
// }

// void	sort_stack(void)
// {
// }