/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/13 19:49:48 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	if (size < 2 ||*stackA == NULL) // When it is already sorted
		return ;
	if (size == 2)
	{
		if ((*stackA)->data > (*stackA)->next->data) // swap a
			sa(stackA);
	}
	else if(size == 3)
		rra(stackA); // reverse rot a
	if ((*stackA)->data < (*stackA)->next->data)
		sa(stackA); // swap
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
