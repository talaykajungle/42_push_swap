/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:27 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/12 23:55:59 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Operation Summary
//Step:					Action:									Effect on Stacks:
//Check Empty:			Verify stack_from has elements		|	Returns - 1 if empty, els proceed
//Remove from Source:	Store top,update stack_from head | 		stack_from loses top element
//Add to Destination: 	If stack_to empty:set as head; else link|stack_to gains new top element
//Return: 				Indicate success 					|	Function ends with 0
int	push(t_list **stack_to, t_list **stack_from)
{
	t_list *tmp;       // Temporary storage for the element being moved
	t_list *head_to;   // points to the head of stack_to
	t_list *head_from; // points to the head of stack_from
	// Uses ft_lstsize to che if stack_from is empty (size 0)
	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;        // Stores current head to "stack_to" for later use
	head_from = *stack_from;    // Stores the current head of "stack_from" which is the top element to move
	tmp = head_from;             // Saves the element in tmp for transfer
	head_from = head_from->next; // Updates "head_from" to next node
	*stack_from = head_from;    // Updates the "stack_from" to reflect the removal
	if (!head_to)                // 1.case if "stack_to" is empty
	{
		head_to = tmp;        // Sets the head to the element being pushed
		head_to->next = NULL; // Ensures it's a single-node list
		*stack_to = head_to;  // Updates the head pointer, tmp makes a new stack
	}
	else // 2.case when it is not empty
	{
		tmp->next = head_to; // links "tmp" to point to the current head,tmp is new top
		*stack_to = tmp;     // Updates the head to tmp,so the new element is at the top
	}
	return (0); // indicates that the push was successful
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
