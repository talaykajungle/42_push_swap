/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:22:04 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/01 15:32:34 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../imports/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//	struct represting a node in the linked list
typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

//	Main
int					main(int argc, char **argv);
void				print_stack(t_list *stack);
t_list				*create_node(int data);
void				add_to_stack(t_list **stack, int data);
void				free_list(t_list **head);
int					is_valid_input(int argc, char *argv[]);


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
int					sorted(t_list *stackA);
int					minimum(t_list *stackA);
void				put_to_top(t_list **stackA, int index, int size);
void				sort3(t_list **stackA);
void				sort4(t_list **stackA, t_list **stackB);
void				sort5(t_list **stackA, t_list **stackB);

#endif