/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/18 21:42:25 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// void	sort_small(t_list **stackA, int size)
// {
// 	if (size < 2 || !*stackA || is_sorted(stackA))
// 		return ;
// 	assign_indices(stackA, size);
// 	if (size == 2)
// 	{
// 		if ((*stackA)->index > (*stackA)->next->index)
// 			sa(stackA);
// 		return ;
// 	}
// 	if ((*stackA)->index == 2) // Largest at top
// 		ra(stackA);
// 	else if ((*stackA)->next->index == 2) // Largest in middle
// 		rra(stackA);
// 	if ((*stackA)->index > (*stackA)->next->index) // Sort top two
// 		sa(stackA);
// }

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
		for (int i = 0; i < size - pos; i++)
			rra(stackA);
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
}

void	simple_sort(t_list **stackA)
{
	int		size;
	t_list	*stackB;

	size = ft_lstsize(*stackA);
	stackB = NULL;
	if (is_sorted(stackA) || size <= 1)
		return ;
	if (size <= 3)
		sort_small(stackA, size);
	else if (size <= 5)
		sort_five(stackA, &stackB);
}
