/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsupport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:26:59 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/17 19:55:51 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*add_node(t_list **stack, t_list **current, int num)
{
	t_list	*new_node;

	new_node = create_node(num);
	if (!new_node)
		return (free_list(*stack, NULL), NULL);
	if (!*stack)
		*stack = new_node;
	else
		(*current)->next = new_node;
	*current = new_node;
	return (*stack);
}

t_list	*build_stack(char **args, int size)
{
	t_list	*stack;
	t_list	*current;
	int		i;
	int		num;

	stack = NULL;
	current = NULL;
	i = 0;
	num = 0;
	if (!args || size <= 0)
		return (NULL);
	while (i < size)
	{
		num = ft_atoi(args[i]);
		if (is_duplicate(stack, num))
			return (free_list(stack, NULL), NULL);
		if (!add_node(&stack, &current, num))
			return (NULL);
		i++;
	}
	return (stack);
}


int	is_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (stack->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
