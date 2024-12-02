/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:14:34 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/02 11:45:50 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>
#include<stdlib.h>

int	*create_int_array(int argc, char *argv[])
{
	int	size;
	int	i;
	int	*arr;

	i = 0;
	size = argc - 1;
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(1);
	}
	while (i < size)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	arr = coordinate_compression(arr, size);
	if (has_duplicates(arr, size))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
//ft_printf("Error\n");

Node* create_node(int num)
{
	Node*	ptr_new_node;

	ptr_new_node = (Node *)malloc(sizeof(Node));
	if (ptr_new_node == NULL)
		return (NULL);
	ptr_new_node->data_num = num;
	ptr_new_node->next = NULL;
	ptr_new_node->prev = NULL;

	return (ptr_new_node);
}

void	append_node(Node **ptr_list_top, Node *ptr_new_node)
{
	Node	*tail;

	if (*ptr_list_top == NULL)
	{
		ptr_new_node->next = ptr_new_node;
		ptr_new_node->prev = ptr_new_node;
		*ptr_list_top = ptr_new_node;
	}
	else
	{
		tail = (*ptr_list_top)->prev;
		ptr_new_node -> next = *ptr_list_top;
		(*ptr_list_top)->prev = ptr_new_node;
		*ptr_list_top = ptr_new_node;
		ptr_new_node->prev = tail;
		tail->next = ptr_new_node;
	}
}

void	append_node_from_back(Node **ptr_list_top, Node *ptr_new_node)
{
	Node	*tail;

	if (*ptr_list_top == NULL)
	{
		ptr_new_node->next = ptr_new_node;
		ptr_new_node->prev = ptr_new_node;
		*ptr_list_top = ptr_new_node;
	}
	else
	{
		tail = (*ptr_list_top)->prev;
		ptr_new_node -> next = *ptr_list_top;
		(*ptr_list_top)->prev = ptr_new_node;
		ptr_new_node->prev = tail;
		tail->next = ptr_new_node;
	}
}
void	print_all_node(Node *list_top)
{
	Node*	Node_to_be_printed;

	if (list_top == NULL)
	{
		ft_printf("this list has nothing.");
		return;
	}
	Node_to_be_printed = list_top;
	ft_printf("%d\n", Node_to_be_printed->data_num);
	Node_to_be_printed = Node_to_be_printed->next;
	while (Node_to_be_printed != list_top)
	{
		ft_printf("%d\n", Node_to_be_printed->data_num);
		Node_to_be_printed = Node_to_be_printed->next;
	}
}
