/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:47 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/27 17:26:02 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	sorted(t_list *stackA)
{
	t_list	*tmp;

	while (stackA && stackA->next)
	{
		tmp = stackA->next;
		if (stackA->data > tmp->data)
			return (0);
		stackA = stackA->next;
	}
	return (1);
}
