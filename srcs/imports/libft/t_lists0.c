/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lists0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:34:37 by codespace         #+#    #+#             */
/*   Updated: 2025/04/07 15:22:51 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstnew(int data)
{
	t_list_libft	*new;

	new = (t_list_libft *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = -1;
	new->next = NULL;
	return (new);
}
