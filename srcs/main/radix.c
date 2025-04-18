/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:27:31 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/18 22:10:54 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	get_max_bits(t_list *stack)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	radix(t_list **stackA, t_list **stackB)
{
	int size = ft_lstsize(*stackA);
	int max_bits = get_max_bits(*stackA);
	int i = 0;
	int j;

	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stackA)->index >> i) & 1) == 0)
				pb(stackA, stackB);
			else
				ra(stackA);
			j++;
		}
		while (*stackB)
			pa(stackA, stackB);
		i++;
	}
}
