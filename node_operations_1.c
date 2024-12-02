/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:30:04 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/02 12:24:35 by dkajiwar         ###   ########.fr       */
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

// void pa(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
// {
// 	Node *tail;
// 	Node *moving_node;
// 	Node *tmp;

// 	if (*ptr_topoflist_b == NULL)
// 		return;
// 	tail = (*ptr_topoflist_b)->prev;
// 	moving_node = create_node((*ptr_topoflist_b)->data_num);
// 	if (moving_node == NULL)
// 	{
// 		free_all_nodes(*ptr_topoflist_a);
// 		free_all_nodes(*ptr_topoflist_b);
// 		return;
// 	}
// 	append_node(ptr_topoflist_a, moving_node);
// 	if ((*ptr_topoflist_b)->next == *ptr_topoflist_b)
// 	{
// 		free((*ptr_topoflist_b));
// 		*ptr_topoflist_b = NULL;
// 		return;
// 	}
// 	(*ptr_topoflist_b)->next->prev = tail;
// 	tail->next = (*ptr_topoflist_b)->next;
// 	tmp = *ptr_topoflist_b;
// 	*ptr_topoflist_b = (*ptr_topoflist_b)->next;
// 	free(tmp);
// }

Node *create_moving_node(Node **ptr_topoflist)
{
    Node *moving_node = create_node((*ptr_topoflist)->data_num);
    if (moving_node == NULL)
    {
        return NULL; // エラーハンドリングは呼び出し元で行う
    }
    return moving_node;
}

void remove_from_stack(Node **ptr_topoflist)
{
    Node *tail = (*ptr_topoflist)->prev;

    if ((*ptr_topoflist)->next == *ptr_topoflist) // リストが1つのノードのみの場合
    {
        free(*ptr_topoflist);
        *ptr_topoflist = NULL;
    }
    else
    {
        (*ptr_topoflist)->next->prev = tail;
        tail->next = (*ptr_topoflist)->next;

        Node *tmp = *ptr_topoflist;
        *ptr_topoflist = (*ptr_topoflist)->next;
        free(tmp);
    }
}

void pa(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
    if (*ptr_topoflist_b == NULL)
        return;

    Node *moving_node = create_moving_node(ptr_topoflist_b);
    if (moving_node == NULL)
    {
        free_all_nodes(*ptr_topoflist_a);
        free_all_nodes(*ptr_topoflist_b);
        return;
    }

    append_node(ptr_topoflist_a, moving_node);
    remove_from_stack(ptr_topoflist_b);
}

//書き直します
void pb(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
    if (*ptr_topoflist_a == NULL)
        return;

    Node *moving_node = create_moving_node(ptr_topoflist_a);
    if (moving_node == NULL)
    {
        free_all_nodes(*ptr_topoflist_a);
        free_all_nodes(*ptr_topoflist_b);
        return;
    }

    append_node(ptr_topoflist_b, moving_node);
    remove_from_stack(ptr_topoflist_a);
}

// void pb(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
// {
// 	Node *tail;
// 	Node *moving_node;
// 	Node *tmp;
	
// 	if (*ptr_topoflist_a == NULL)
// 		return;
// 	tail = (*ptr_topoflist_a)->prev;
// 	moving_node = create_node((*ptr_topoflist_a)->data_num);
// 	if (moving_node == NULL)
// 	{
// 		free_all_nodes(*ptr_topoflist_a);
// 		free_all_nodes(*ptr_topoflist_b);
// 		return;
// 	}
// 	append_node(ptr_topoflist_b, moving_node);
// 	if ((*ptr_topoflist_a)->next == *ptr_topoflist_a)
// 	{
// 		free((*ptr_topoflist_a));
// 		*ptr_topoflist_a = NULL;
// 		return;
// 	}
// 	(*ptr_topoflist_a)->next->prev = tail;
// 	tail->next = (*ptr_topoflist_a)->next;
// 	tmp = *ptr_topoflist_a;
// 	*ptr_topoflist_a = (*ptr_topoflist_a)->next;
// 	free(tmp);
// }
