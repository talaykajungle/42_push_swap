/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:30:18 by tamutlu           #+#    #+#             */
/*   Updated: 2025/05/21 17:31:53 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_small(t_list **stackA, int size)
{
	if (size < 2 || !*stackA || is_sorted(stackA))
		return ;
	assign_indices(stackA, size);
	if (size == 2)
	{
		if ((*stackA)->data > (*stackA)->next->data)
			sa(stackA);
		return ;
	}
	if ((*stackA)->index == 2)
		ra(stackA);
	else if ((*stackA)->next->index == 2)
		rra(stackA);
	if ((*stackA)->data > (*stackA)->next->data)
		sa(stackA);
}

void	push_smallest(t_list **stackA, t_list **stackB, int target_index)
{
	int		pos;
	int		size;
	int		i;
	t_list	*current;

	pos = 0;
	size = ft_lstsize(*stackA);
	current = *stackA;
	while (current && current->index != target_index)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stackA);
	else
	{
		i = 0;
		while (i++ < size - pos)
			rra(stackA);
	}
	pb(stackA, stackB);
}

void	sort_five(t_list **stackA, t_list **stackB)
{
	assign_indices(stackA, 5);
	push_smallest(stackA, stackB, 0);
	push_smallest(stackA, stackB, 1);
	sort_small(stackA, 3);
	if ((*stackA)->index < (*stackB)->next->index)
		sa(stackB);
	pa(stackA, stackB);
	pa(stackA, stackB);
}

void	simple_sort(t_list **stackA)
{
	int		size;
	t_list	*stackb;

	size = ft_lstsize(*stackA);
	stackb = NULL;
	if (is_sorted(stackA) || size <= 1)
		return ;
	if (size <= 3)
		sort_small(stackA, size);
	else if (size <= 5)
		sort_five(stackA, &stackb);
	else
		radix(stackA, &stackb);
}
