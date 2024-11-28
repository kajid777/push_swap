/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:30:04 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/28 20:04:00 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(Node **ptr_topoflist_a)
{
	int tmp;
	
	if ((*ptr_topoflist_a) == NULL)
	{
		return;
	}
	if ((*ptr_topoflist_a)->next ==(*ptr_topoflist_a) || (*ptr_topoflist_a) == NULL)
	{
		return;
	}
	tmp = (*ptr_topoflist_a)->next->data_num;
	(*ptr_topoflist_a)->next->data_num = (*ptr_topoflist_a)->data_num;
	(*ptr_topoflist_a)->data_num = tmp;
}
//三番目のprevを最初に変更する
//次にtailのnextを変更する

void sb(Node **ptr_topoflist_b)
{
	int tmp;

	if ((*ptr_topoflist_b) == NULL)
	{
		return;
	}
	if ((*ptr_topoflist_b)->next ==(*ptr_topoflist_b))
	{
		return;
	}
	tmp = (*ptr_topoflist_b)->next->data_num;
	(*ptr_topoflist_b)->next->data_num = (*ptr_topoflist_b)->data_num;
	(*ptr_topoflist_b)->data_num = tmp;
}

void ss(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
	sa(ptr_topoflist_a);
	sb(ptr_topoflist_b);
}

void pa(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
	Node *tail;
	Node *moving_node;
	Node *tmp;

	if (*ptr_topoflist_b == NULL)
	return;
		tail = (*ptr_topoflist_b)->prev;
	moving_node = create_node((*ptr_topoflist_b)->data_num);
	append_node(ptr_topoflist_a, moving_node);
	if ((*ptr_topoflist_b)->next == *ptr_topoflist_b)
	{
		free((*ptr_topoflist_b));
		*ptr_topoflist_b = NULL;
		return;
	}
	(*ptr_topoflist_b)->next->prev = tail;
	tail->next = (*ptr_topoflist_b)->next;
	tmp = *ptr_topoflist_b;
	*ptr_topoflist_b = (*ptr_topoflist_b)->next;
	free(tmp);
}

void pb(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
	Node *tail;
	Node *moving_node;
	Node *tmp;
	
	if (*ptr_topoflist_a == NULL)
		return;
	tail = (*ptr_topoflist_a)->prev;
	moving_node = create_node((*ptr_topoflist_a)->data_num);
	append_node(ptr_topoflist_b, moving_node);

	if ((*ptr_topoflist_a)->next == *ptr_topoflist_a)
	{
		free((*ptr_topoflist_a));
		*ptr_topoflist_a = NULL;
		return;
	}
	(*ptr_topoflist_a)->next->prev = tail;
	tail->next = (*ptr_topoflist_a)->next;
	tmp = *ptr_topoflist_a;
	*ptr_topoflist_a = (*ptr_topoflist_a)->next;
	free(tmp);
}
