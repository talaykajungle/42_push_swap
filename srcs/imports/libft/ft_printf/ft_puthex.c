/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:47:27 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/28 16:11:07 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthex(unsigned int a, char format, int *len)
{
	if (a == 0)
	{
		write(1, "0", 1);
		(*len)++;
		return ;
	}
	if (a >= 16)
		ft_puthex(a / 16, format, len);
	if (format == 'X')
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	else if (format == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	(*len)++;
}
