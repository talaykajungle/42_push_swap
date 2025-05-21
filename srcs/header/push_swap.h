/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:22:04 by tamutlu           #+#    #+#             */
/*   Updated: 2025/05/21 16:49:02 by tamutlu          ###   ########.fr       */
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

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

//	Main
int					main(int argc, char **argv);
void				print_list(t_list *stack);
void				free_list(t_list *head, t_list *head2);
t_list				*create_node(int data);
void				sort_stack(t_list **stackA);
void				radix(t_list **stackA, t_list **stackB);
void				free_args(int argc, char **args);
void				arg_check(int argc, char **argv);

// Main Support
t_list				*build_stack(char **args, int size);
t_list				*add_new_node(t_list **stack, t_list **current, int num);
int					is_duplicate(t_list *stack, int num);

//	Rules
//	push ops
int					push(t_list **stack_to, t_list **stack_from);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);

//	rot ops
int					reverse(t_list **stackA);
int					rra(t_list **stackA);
int					rrb(t_list **stackB);
int					rrr(t_list **stackA, t_list **stackB);

//	rev_rot_ops
int					rotate(t_list **stack);
int					ra(t_list **stackA);
int					rb(t_list **stackB);
int					rr(t_list **stackA, t_list **stackB);

//	swap_ops
int					swap(t_list **stackA);
int					sa(t_list **stackA);
int					sb(t_list **stackB);
int					ss(t_list **stackA, t_list **stackB);

//	Sorts
//	Sort checker
void				assign_indices(t_list **stackA, int size);
void				sort_small(t_list **stackA, int size);
int					is_sorted(t_list **stack);
void				simple_sort(t_list **stackA);
void				push_smallest(t_list **stackA, t_list **stackB,
						int target_index);
void				sort_five(t_list **stackA, t_list **stackB);

// list rules
t_list				*ft_lstnew(int data);
t_list				*ft_lstadd_front(t_list **stack, t_list *new);
t_list				*ft_lstlast(t_list *head);
int					ft_lstadd_back(t_list **stack, t_list *new);
int					ft_lstsize(t_list *head);
int					printlist(t_list *head);

#endif