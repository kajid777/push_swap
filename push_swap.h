/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:26:21 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/12 21:43:46 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H  // インクルードガード
#define PUSH_SWAP_H

#include<stddef.h>
#include<stdlib.h>

typedef struct Node
{
	int data_num;
	struct Node	*next;
	struct Node	*prev;
}	Node;

	void append_node(Node **ptr_list_top, Node *new_Node);
	void print_all_node(Node *list_top);
	Node* create_node(int num);
	int	ft_atoi(const char *str);
	char	**ft_split(const char *str, char c);
	int	ft_printf(const char *str, ...);
	int has_duplicates(int *arr, int size);
	int *create_int_array(int argc, char *argv[]);
	Node *free_all_nodes(Node *topoflist);

	//sort.c
	void sort(Node **ptr_topoflist_a, Node **ptr_topoflist_b);

	//node_operations_1.c
	void sa(Node **topoflist_a);
	void sb(Node **topoflist_b);
	void ss(Node **ptr_topoflist_a, Node **ptr_topoflist_b);
	void pa(Node **topoflist_a, Node **topoflist_b);
	void pb(Node **ptr_topoflist_a, Node **ptr_topoflist_b);

	//node_operations_2.c
	void ra(Node **topoflist_a);
	void rb(Node **topoflist_b);
	void rr(Node **topoflist_a, Node **topoflist_b);

	//node_operations_3.c
	void rra(Node **topoflist_a);
	void rrb(Node **topoflist_b);
	void rrr(Node **topoflist_a, Node **topoflist_b);	

#endif  // PUSH_SWAP_H
