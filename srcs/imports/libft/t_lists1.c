/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lists1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:45:48 by codespace         #+#    #+#             */
/*   Updated: 2025/04/07 15:22:40 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the specified node to the list (Makes the head of the node)
t_list_libft	*ft_lstadd_front(t_list_libft **stack, t_list_libft *new)
{
	new->next = *stack;
	*stack = new;
}

// Returns the last Node of the list
t_list_libft	*ft_lstlast(t_list_libft *head)
{
	t_list_libft	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to the Stack (Making it the last node)
void	ft_lstadd_back(t_list_libft **stack, t_list_libft *new)
{
	t_list_libft	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

// Returns the size of the linked list
int	ft_lstsize(t_list_libft *head)
{
	size_t			i;
	t_list_libft	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// Prints the linked list
void	printlist(t_list_libft *head)
{
	t_list_libft	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
