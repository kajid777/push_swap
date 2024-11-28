/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:47:34 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/27 18:35:38 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
// {
// 	int max_bit_len;
// 	int init_stack_a_size;
// 	int i;
// 	int j;
// 	int k;
// 	Node *head_a;
// 	i = 0;
// 	init_stack_a_size = get_stack_size(*ptr_topoflist_a);
// 	max_bit_len = get_max_bit_len(*ptr_topoflist_a);
// 	ft_printf("test:max_bit_len:%d\n", max_bit_len);
// 	ft_printf("test:stack_a_size:%d\n", init_stack_a_size);
// 	while(i < max_bit_len)
// 	{
// 		j = 0;
// 		k = 0;
// 		while(j < init_stack_a_size)
// 		{
// 			head_a = *ptr_topoflist_a;
// 			if (((head_a->data_num >> i) & 1) == 1)
// 				ra(ptr_topoflist_a);
// 			else
// 			{
// 				pb(ptr_topoflist_a, ptr_topoflist_b);
// 				k++;
// 			}
// 			j++;
// 		}
// 		//ここでスタックｂの内容を全部pa
// 		j = 0;
// 		while(j < k)
// 		{
// 			pa(ptr_topoflist_a, ptr_topoflist_b);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void sort(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
    int max_bit_len;
    int init_stack_a_size;
	int i;

	max_bit_len = get_max_bit_len(*ptr_topoflist_a);
	init_stack_a_size = get_stack_size(*ptr_topoflist_a);
	i = 0;
    while (i < max_bit_len)
    {
        int moved_count = move_based_on_bit(ptr_topoflist_a, ptr_topoflist_b, i, init_stack_a_size);
        restore_stack_b(ptr_topoflist_a, ptr_topoflist_b, moved_count);
        i++;
    }
}
// ft_printf("test:max_bit_len:%d\n", max_bit_len);
// ft_printf("test:stack_a_size:%d\n", init_stack_a_size);

// 1ビットに基づいてスタックaからbに移動する部分
int move_based_on_bit(Node **ptr_topoflist_a, Node **ptr_topoflist_b, int bit_index, int stack_size)
{
    Node *head_a;
    int moved_count = 0;
	int j;

	j = 0;
    while (j < stack_size)
    {
        head_a = *ptr_topoflist_a;
        if (((head_a->data_num >> bit_index) & 1) == 1)
        {
            ra(ptr_topoflist_a);
        }
        else
        {
            pb(ptr_topoflist_a, ptr_topoflist_b);
            moved_count++;
        }
		j++;
    }
    return moved_count;
}

// スタックbの内容をスタックaに戻す部分
void restore_stack_b(Node **ptr_topoflist_a, Node **ptr_topoflist_b, int moved_count)
{
	int	j;
	
	j = 0;
    while (j < moved_count)
    {
        pa(ptr_topoflist_a, ptr_topoflist_b);
        j++;
    }
}
