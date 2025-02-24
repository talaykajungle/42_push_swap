/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:22:04 by tamutlu           #+#    #+#             */
/*   Updated: 2025/02/24 19:05:35 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

//	struct represting a node in the linked list
typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

//	Rules
//	push ops
void				push_a(t_list **stackA, t_list **stackB);
void				push_b(t_list **stackA, t_list **stackB);

//	rot ops
void				rot_a(t_list **stackA);
void				rot_b(t_list **stackB);
void				rot_ab(t_list **stackA, t_list **stackB);

//	rev_rot_ops
void				rev_rot_a(t_list **stackA);
void				rev_rot_b(t_list **stackB);
void				rev_rot_ab(t_list **stackA, t_list **stackB);

//	swap_ops
void				swap_a(t_list **stackA);
void				swap_b(t_list **stackB);
void				swap_ab(t_list **stackA, t_list **stackB);

//	Sorts
//	Sort checker
int					sorting(t_list *stackA);
int					minimum(t_list *stackA);
void				sort3(t_list **stackA);
void				sort5(t_list **stackA);

#endif