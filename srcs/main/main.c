/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:33 by tamutlu           #+#    #+#             */
/*   Updated: 2025/05/21 16:48:31 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static char	**get_args(int argc, char **argv, int *size)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		i = 0;
		while (args[i])
			i++;
		*size = i;
	}
	else
	{
		args = argv + 1;
		*size = argc - 1;
	}
	return (args);
}

void	free_args(int argc, char **args)
{
	int	i;

	if (argc != 2 || !args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	char	**args;
	int		size;

	stacka = NULL;
	stackb = NULL;
	if (argc < 1)
		return (0);
	arg_check(argc, argv);
	args = get_args(argc, argv, &size);
	if (!args || size == 0)
		return (ft_putstr_fd("Error\n", 2), free_args(argc, args), 1);
	stacka = build_stack(args, size);
	free_args(argc, args);
	if (!stacka)
		return (ft_putstr_fd("Error\n", 2), free_list(stacka, stackb), 1);
	if (is_sorted(&stacka))
		return (free_list(stacka, stackb), 0);
	sort_stack(&stacka);
	return (free_list(stacka, stackb), 0);
}
