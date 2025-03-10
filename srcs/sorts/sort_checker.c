/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:47 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/10 16:10:49 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Assign indices to stackA based on how many numbers are smaller than its data

void	assign_indicies(t_list **stackA, int size)
{
	t_list	*current;
	t_list	*checker;
	int		count;

	count = 0;
	if (!*stackA || size <= 1)
	{
		if (*stackA)
			(*stackA)->index = 0;
		return ;
	}
	current = *stackA;
	checker = *stackA;
	while (checker != NULL)
	{
		if (checker->data < current->data)
			count++;
		checker = checker->data;
	}
}

void	sort_small(t_list **stackA)
{
}

void	sort_large(void)
{
}

void	sort_stack(void)
{
}