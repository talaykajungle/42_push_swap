/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:20:21 by tamutlu           #+#    #+#             */
/*   Updated: 2025/05/20 18:46:54 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_error(char *note, int argc, char **args)
{
	int	indx;

	indx = 0;
	if (argc == 2)
	{
		if (!args)
			return ;
		while (args[indx])
		{
			free(args[indx]);
			indx++;
		}
		free(args);
	}
	ft_putendl_fd(note, 1);
	exit(0);
}
/*
Checks if the given string contains only numbers
Skips the minus sign if it encounters one
Returns 1 if the string is a valid number, 0 if not
*/
static int	num_check(char *n)
{
	int	indx;
	int	return_val;

	indx = 0;
	return_val = 0;
	if (n[indx] == '-')
		indx++;
	while (n[indx])
	{
		if (ft_isdigit(n[indx]))
		{
			return_val = 1;
			indx++;
		}
		else
			ft_error("Error: Arguments contain character(s)", 0, NULL);
	}
	return (return_val);
}

/*
Function checks for duplicate values within the given parameters.
If a duplicate is found, the proper error message is displayed and the
program exits.
*/
static int	dup_check(char **args, long temp, int indx)
{
	indx++;
	while (args[indx])
	{
		if (ft_atoi(args[indx]) == temp)
			return (1);
		indx++;
	}
	return (0);
}

/*
Validates the user-input arguments:
- Checks if all arguments are valid numbers
- Checks for duplicate values within the arguments.
- Ensures each number is within the range of INT_MIN to INT_MAX
- Handles both space-separated numbers in a single argument
  and multiple arguments
Outputs Error and Exits if any validation fails
*/
void	arg_check(int argc, char **argv)
{
	int		indx;
	long	temp;
	char	**args;

	indx = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		indx = 1;
		args = argv;
	}
	while (args[indx])
	{
		if (!num_check(args[indx]))
			ft_error("Error: Arguments contain character(s)", argc, args);
		temp = ft_atoi(args[indx]);
		if (dup_check(args, temp, indx))
			ft_error("Error: Parameters contain duplicates", argc, args);
		if (temp < -2147483648 || temp > 2147483647)
			ft_error("Error: Integer value paramaters exceeded", argc, args);
		indx++;
	}
	if (argc == 2)
		free_args(argc, args);
}
