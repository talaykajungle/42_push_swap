/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talaykajungle <talaykajungle@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:47 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/21 18:59:43 by talaykajung      ###   ########.fr       */
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

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
