/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsupport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:26:59 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/15 20:54:32 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*build_stack(char **argc,char **argv,int size)
{
	t_list	*stack;
	t_list	*current;
	int		i;
	int		num;
	t_list	*new_node;

	stack = NULL;
	current = NULL;
	i = 0;
	if (!args || size <= 0)
		return (NULL);
	while (i < size)
	{
		num = ft_atoi(args[i]);
		if (is_duplicate(stack, num))
		{
			free_list(stack);
			return (NULL);
		}
		new_node = create_node(num);
		if (!new_node)
		{
			free_list(stack);
			return (NULL);
		}
		if (!stack)
		{
			stack = new_node;
		}
		else
			current->next = new_node;
		current = new_node;
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
