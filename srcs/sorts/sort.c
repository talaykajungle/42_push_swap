/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/19 22:47:27 by tamutlu          ###   ########.fr       */
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

void	swap_a(t_list **stackA);
void	rot_a(t_list **stackA);
void	rev_rot_a(t_list **stackA);

void	sort_small(t_list **stackA, int size)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (size < 2 || *stackA == NULL)
		return ;
	first = *stackA;
	second = first->next;
	if (size == 2)
	{
		if (first->data > second->data)
			swap_a(stackA);
		return ;
	}
	third = second->next;
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