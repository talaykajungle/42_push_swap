/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:24:26 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/04 15:59:50 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	minimum(t_list *stackA)
{
	int min;            // Stroes the minimum value
	int min_index;      // stores the index of the minimum value
	int index;          // tracks the current position
	t_list *stacknow;   // pointer to go over the list
	if (!stackA)        // Handels an empty list
		return (-1);    // Returns -1 for a invalid list
	min = stackA->data; // Initializes min with first node data
	min_index = 0;      // Initializes min_index to 0
	index = 0;          // starts index at 0
	stacknow = stackA;  // starts from the first node
	while (stacknow)
	{
		if (stacknow->data < min)
		{
			min = stacknow->data;
			min_index = index;
		}
		stacknow = stacknow->next;
		index++;
	}
	return (min_index);
}

void	put_to_top(t_list **stackA, int index, int size)
{
	printf("put_to_top: index=%d, size=%d\n", index, size);
	if (index <= size / 2)
	{
		while (index-- > 0)
		{
			rot_a(stackA);
		}
	}
	else
	{
		while (index++ < size)
		{
			rev_rot_a(stackA);
		}
	}
}

// void	sort3(t_list **stackA)
// {
// 	if (sorted(*stackA))
// 		return ;
// 	if (minimum(*stackA) == 0)
// 	{
// 		swap_a(stackA);
// 		rot_a(stackA);
// 	}
// 	else if (minimum(*stackA) == 1)
// 	{
// 		if ((*stackA)->data < (*stackA)->next->next->data)
// 			swap_a(stackA);
// 		else
// 			rot_a(stackA);
// 	}
// 	else
// 	{
// 		if ((*stackA)->data < (*stackA)->next->data)
// 			rev_rot_a(stackA);
// 		else
// 			swap_a(stackA);
// 		rev_rot_a(stackA);
// 	}
// }

void	sort3(t_list **stackA)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stackA)->data;
	mid = (*stackA)->next->data;
	bot = (*stackA)->next->next->data;
	if (sorted(*stackA))
		return ;
	if (top > mid && mid < bot && top < bot)
		swap_a(stackA);
	else if (top < mid && mid > bot && top < bot)
	{
		swap_a(stackA);
		rot_a(stackA);
	}
	else if (top > mid && mid > bot)
	{
		swap_a(stackA);
		rev_rot_a(stackA);
	}
	else if (top > mid && mid < bot)
		rot_a(stackA);
	else if (top < mid && mid > bot)
		rev_rot_a(stackA);
}

void	sort4(t_list **stackA, t_list **stackB)
{
	printf("Starting sort4\n");
	printf("Calling put_to_top with min index %d\n", minimum(*stackA));
	put_to_top(stackA, minimum(*stackA), 4);
	printf("After put_to_top\n");
	if (sorted(*stackA))
	{
		printf("Stack is sorted, exiting\n");
		return ;
	}
	printf("Pushing to B\n");
	push_b(stackA, stackB);
	printf("Calling sort3\n");
	sort3(stackA);
	printf("Pushing back to A\n");
	push_a(stackA, stackB);
	printf("Finished sort4\n");
}

void	sort5(t_list **stackA, t_list **stackB)
{
	put_to_top(stackA, minimum(*stackA), 5);
	if (sorted(*stackA))
		return ;
	push_b(stackA, stackB);
	sort4(stackA, stackB);
	push_a(stackA, stackB);
}
