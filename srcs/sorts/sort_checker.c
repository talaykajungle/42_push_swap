/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:47 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/24 16:52:36 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting(t_list *stackA)
{
	t_list *temp;

	while (stackA && stackA->next)
	{
		temp = stackA->next;
		if (stackA->data > temp->data)
			return (0);
		stackA = stackA->next;
	}
	return (1);
}