/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:01:10 by tamutlu           #+#    #+#             */
/*   Updated: 2025/05/21 20:26:00 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_atoi(const char *str, int *error)
// {
// 	long	res;
// 	int		sign;

// 	*error = 0;
// 	res = 0;
// 	sign = 1;
// 	ft_isspace(*str);
// 	if (*str == '-' || *str == '+')
// 		sign = (*str++ == '-') ? -1 : 1;
// 	if (!ft_isdigit(*str))
// 		*error = 1;
// 	while (ft_isdigit(*str))
// 	{
// 		res = res * 10 + (*str++ - '0');
// 		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
// 			*error = 1;
// 	}
// 	if (*str != '\0')
// 		*error = 1;
// 	return ((int)res * sign);
// }

long	ft_atoi(const char *str, int *error)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	*error = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		*error = 1;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	if (*str && !*error)
		*error = 1;
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
	{
		*error = 1;
		return (1);
	}
	return (res);
}
