/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:47 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/05 11:51:36 by tamutlu          ###   ########.fr       */
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

void	sort_stack(t_list **stackA, t_list **stackB, int count)
{
	if (count == 3)
		sort3(stackA);
	else if (count == 4)
		sort4(stackA, stackB);
	else if (count == 5)
		sort5(stackA, stackB);
	else
		ft_printf("Sorting not implemented for %d elements\n", count);
}

int	load_stack(t_list **stackA, int argc, char **argv)
{
	char **args = NULL;
	int i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !is_valid_input_split(args))
		{
			ft_free_split(args);
			return (0);
		}
		while (args[i])
			add_to_stack(stackA, ft_atoi(args[i++]));
		ft_free_split(args);
	}
	else
	{
		if (!is_valid_input(argc, argv))
			return (0);
		i = 1;
		while (i < argc)
			add_to_stack(stackA, ft_atoi(argv[i++]));
		i = argc - 1;
	}
	return (i);
}
