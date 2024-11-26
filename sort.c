/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:47:34 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/26 20:28:16 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
	int max_bit_len;
	int init_stack_a_size;
	int i;
	int j;
	int k;
	Node *head_a;
	
	i = 0;
	
	init_stack_a_size = get_stack_size(*ptr_topoflist_a);
	max_bit_len = get_max_bit_len(*ptr_topoflist_a);
	(void)ptr_topoflist_b;
	ft_printf("test:max_bit_len:%d\n", max_bit_len);
	ft_printf("test:stack_a_size:%d\n", init_stack_a_size);
	
	while(i < max_bit_len)
	{
		
		j = 0;
		k = 0;
		while(j < init_stack_a_size)
		{
			head_a = *ptr_topoflist_a;
			if (((head_a->data_num >> i) & 1) == 1)
				ra(ptr_topoflist_a);
			else
			{
				pb(ptr_topoflist_a, ptr_topoflist_b);
				k++;
			}
			j++;
		}
		//ここでスタックｂの内容を全部pa
		j = 0;
		while(j < k)
		{
			pa(ptr_topoflist_a, ptr_topoflist_b);
			j++;
		}
		i++;
	}
}