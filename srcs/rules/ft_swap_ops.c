/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:35 by tamutlu           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/27 17:15:27 by codespace        ###   ########.fr       */
=======
/*   Updated: 2025/03/21 16:05:13 by tamutlu          ###   ########.fr       */
>>>>>>> 95b655a505abce0183dfc65b09db94d51ec6b342
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//	Swaps the first 2 elements at the top of the stack a
<<<<<<< HEAD

int	swap(t_list **stackA)
=======
void	swap_a(t_list **stackA)
>>>>>>> 95b655a505abce0183dfc65b09db94d51ec6b342
{
	t_list *head;
	t_list *next;
	int	tmp_dat;
	int	tmp_index;

<<<<<<< HEAD
	
=======
	if (!stackA || !*stackA || !(*stackA)->next)
		return ;
	first = *stackA;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stackA = second;
	write(1, "sa\n", 3);
}

//	Swaps the first 2 elements at the top of the stack b
void	swap_b(t_list **stackB)
{
	t_list	*first;
	t_list	*second;

	if (!stackB || !*stackB || !(*stackB)->next)
	{
		return ;
	}
	first = *stackB;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stackB = second;
}

//	Swaps the first 2 elements of both stack at the same time
void	swap_ab(t_list **stackA, t_list **stackB)
{
	t_list	*first;
	t_list	*second;

	if (stackA && *stackA && (*stackA)->next)
	{
		first = *stackA;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stackA = second;
	}
	if (stackB && *stackB && (*stackB)->next)
	{
		first = *stackB;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stackB = second;
	}
>>>>>>> 95b655a505abce0183dfc65b09db94d51ec6b342
}
