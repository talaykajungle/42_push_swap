/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/15 20:41:39 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// void	sort_small(t_list **stackA, int size)
// {
// 	if (size < 2 || *stackA == NULL) // When it is already sorted
// 		return ;
// 	if ((*stackA)->data > (*stackA)->next->data) // swap a
// 		sa(stackA);
// 	if (size == 3)
// 	{
// 		rra(stackA); // reverse rot a
// 	}
// 	else
// 		ra(stackA); // rotate
// 	if ((*stackA)->data > (*stackA)->next->data)
// 		ra(stackA);
// 	if ((*stackA)->data > (*stackA)->next->data)
// 	{
// 		sa(stackA);
// 		ra(stackA);
// 	}
// }

/*
1 2 3	nothing already sorted	!"done"!
1 3 2	reverse rot a			!"done"!
2 1 3	swap a					!"done"!
2 3 1	swap & rotate			!"done"!
3 1 2	rotate a				!""!
3 2 1	swap & reverse rotate	!""!

bigger ">" smaller "<"
*/

void	sort_small(t_list **stackA, int size)
{
	if (size < 2 || *stackA == NULL)
		return ;
	if (size == 2)
	{
		if ((*stackA)->data >= (*stackA)->next->data)
			sa(stackA);
		return ;
	}
	if (size == 3)
	{
		sa(stackA);
		rra(stackA); // reverse rot a
	}
	else
		ra(stackA); // rotate
	if ((*stackA)->data > (*stackA)->next->data)
		ra(stackA);
	if ((*stackA)->data > (*stackA)->next->data)
	{
		sa(stackA);
		ra(stackA);
	}
}

void	simple_sort(t_list **stackA)
{
	int size;

	if (is_sorted(stackA) || ft_lstsize(*stackA) == 0
		|| ft_lstsize(*stackA) == 1)
		return ;
	size = ft_lstsize(*stackA);
	if (size == 2)
		sa(stackA);
	// else if (size == 3)
	// 	sort_small(stackA, size);
	// else if (size == 4)
	// 	sort_4(*stackA, stackB);
	// else if (size == 5)
	// 	sort_5(*stackA, stackB);
}