/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:22:04 by tamutlu           #+#    #+#             */
/*   Updated: 2025/03/21 15:34:02 by tamutlu          ###   ########.fr       */
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
	int data;  // original number
	int index; // sorted position
	struct s_list	*next;
}				t_list;


//	Main
// int					main(int argc, char **argv);
int	main(int argc, char **argv);
void				print_list(t_list *stack);
void				free_list(t_list *head);
t_list				*create_node(int data);
void				test_sort_small(int a, int b, int c);
//void				test_swap_a(void);


// Main Support
t_list				*build_stack(char **args, int size);
int					is_duplicate(t_list *stack, int num);

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
void				assign_indices(t_list **stackA, int size);
void				sort_small(t_list **stackA, int size);
void				sort_3(t_list **stackA, int size);

#endif