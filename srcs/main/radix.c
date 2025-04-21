/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talaykajungle <talaykajungle@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:27:31 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/21 20:11:07 by talaykajung      ###   ########.fr       */
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
	int size;
	int max_bits;
	int i;
	int processed;

	size = ft_lstsize(*stackA);
	max_bits = get_max_bits(*stackA);
	i = 0;
	while (i < max_bits)
    {
        processed = 0;
        while (processed < size && *stackA)
        {
            if ((((*stackA)->index >> i) & 1) == 0)
                pb(stackA, stackB);
            else
                ra(stackA);
            processed++;
        }
        while (*stackB)
            pa(stackA, stackB);
        i++;
    }
}

