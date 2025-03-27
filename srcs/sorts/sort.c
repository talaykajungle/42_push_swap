/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/21 15:50:22 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// This function is to sort 2,3,4 or 5 numbers using simple move like (sa,ra,rra) etc.

// void	sort_small(t_list **stackA, int size)
// {
// 	t_list	*first;
// 	t_list	*second;

// 	if (size < 2 || *stackA == NULL || (*stackA)->next == NULL)
// 		return ;
// 	first = *stackA;
// 	second = first->next;
// 	first = *stackA;
// 	second = first->next;
// 	if (first->data > second->data)
// 		swap_a(stackA);
// }

// void	sort_3(t_list **stackA, int size)
// {
// 	t_list	*first;
// 	t_list	*second;
// 	t_list	*third;

// 	if (size == 3)
// 	{
// 		first = *stackA;
// 		second = first->next;
// 		third = second->next;
// 	}
// }

void	sort_small(t_list **stackA, int size)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (size < 2 || *stackA == NULL)
		return ;
	first = *stackA;
	second = first->next;
	third = second->next;
	if (size == 2 || size == 3)
	{
		if (first->data > second->data && second->data > third->data)
		{	
			swap_a(stackA);
			rev_rot_a(stackA);
		}
		return ;
	}
	if (first->data > second->data)
		swap_a(stackA);
	if (first->data > third->data)
	{
		rev_rot_a(stackA);
		if (first->data > second->data)
			swap_a(stackA);
	}
	if (second->data > third->data)
		rot_a(stackA);
}

// void	sort_stack(void)
// {
// }