/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:30:04 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/27 18:48:12 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(Node **ptr_topoflist_a)
{
	int tmp;
	
	if ((*ptr_topoflist_a)->next ==(*ptr_topoflist_a) || (*ptr_topoflist_a) == NULL)
		return;
	tmp = (*ptr_topoflist_a)->next->data_num;
	(*ptr_topoflist_a)->next->data_num = (*ptr_topoflist_a)->data_num;
	(*ptr_topoflist_a)->data_num = tmp;
	ft_printf("sa\n");
}
//三番目のprevを最初に変更する
//次にtailのnextを変更する

void sb(Node **ptr_topoflist_b)
{
	if ((*ptr_topoflist_b) == NULL)
	{
		ft_printf("sb\n");
		return;
	}
	if ((*ptr_topoflist_b)->next ==(*ptr_topoflist_b))
	{
		ft_printf("sb\n");
		return;
	}
	int tmp;
	tmp = (*ptr_topoflist_b)->next->data_num;
	(*ptr_topoflist_b)->next->data_num = (*ptr_topoflist_b)->data_num;
	(*ptr_topoflist_b)->data_num = tmp;
	ft_printf("sb\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
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
