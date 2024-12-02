/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:26:21 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/02 11:18:13 by dkajiwar         ###   ########.fr       */
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
    void	append_node_from_back(Node **ptr_list_top, Node *ptr_new_node);

	//node_initialization.c
	void print_all_node(Node *list_top);
	Node* create_node(int num);
	int	ft_atoi(const char *str);
	char	**ft_split(const char *str, char c);
	int	ft_printf(const char *str, ...);
	int has_duplicates(int *arr, int size);
	int *create_int_array(int argc, char *argv[]);
	Node *free_all_nodes(Node *topoflist);

	//coordinate_compression.c
	void selection_sort(int *arr, int arr_size);
	int *copy_array(int *arr, int arr_size);
	int index_finder(int *copied_arr, int arr_size, int num);
	void set_coordinate(int *arr, int *copied_arr, int *dest_arr, int arr_size);
	int *coordinate_compression(int *arr, int arr_size);

	//main.c
	Node*   make_list_y(const char *str);
	int *convert_to_int_array(char **str_array, int *size);
	
	//simple_sort.c
	int	get_min_num(Node *ptr_list);
	void	sort_3(Node **stack);
	void	sort_4(Node **stack_a, Node **stack_b);
	void	sort_5(Node **stack_a, Node **stack_b);
	void	simple_sort(Node **stack_a, Node **stack_b);
	int		is_sorted(Node **stack);
	
	//sort_3_mods.c
	void sort_3_mod_1(Node **stack);
	void sort_3_mod_2(Node **stack);
	void sort_3_mod_3(Node **stack);
	void sort_3_mod_4(Node **stack);
	void sort_3_mod_5(Node **stack);
	//sort_4_mods.c
	void sort_4_mod_1(Node **stack_a, Node **stack_b);
	void sort_4_mod_2(Node **stack_a, Node **stack_b);
	void sort_4_mod_3(Node **stack_a, Node **stack_b);
	void sort_4_mod_4(Node **stack_a, Node **stack_b);
	//sort_5_mods.c
	void sort_5_mod_1(Node **stack_a, Node **stack_b);
	void sort_5_mod_2(Node **stack_a, Node **stack_b);
	void sort_5_mod_3(Node **stack_a, Node **stack_b);
	void sort_5_mod_4(Node **stack_a, Node **stack_b);
	void sort_5_mod_5(Node **stack_a, Node **stack_b);
	//sort.c
	void sort(Node **ptr_topoflist_a, Node **ptr_topoflist_b);
	int move_based_on_bit(Node **ptr_topoflist_a, Node **ptr_topoflist_b, int bit_index, int stack_size);
	void restore_stack_b(Node **ptr_topoflist_a, Node **ptr_topoflist_b, int moved_count);
	
	//utils.c
	int	get_stack_size(Node *list_top);
	int	is_sorted(Node **stack);
	int	pattern_identify_y(Node **stack, int data_num);
	int pattern_identify_x(Node **stack);


	//bit_operations.c
	int get_max_num(Node *ptr_list);
	int get_max_bit_len(Node *ptr_list);
	
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
