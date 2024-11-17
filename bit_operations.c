/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:26:55 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/15 16:09:24 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_num(Node *ptr_list)
{
	int max;
	Node	*Node_to_be_compared;
	if (ptr_list == NULL)
	{
		ft_printf("this list has nothing.");
		return (-1);
	}
	Node_to_be_compared = ptr_list;
	max = Node_to_be_compared->data_num;
	ft_printf("%d\n", Node_to_be_compared->data_num);
	Node_to_be_compared = Node_to_be_compared->next;
	while (Node_to_be_compared != ptr_list)
	{
		if (max < Node_to_be_compared->data_num)
		{
			max = Node_to_be_compared->data_num;
		}
		Node_to_be_compared = Node_to_be_compared->next;
	}
	return (max);
}

int get_max_bit_len(Node *ptr_list)
{
	int bit_len;
	int max_num;

	bit_len = 0;
	max_num = get_max_num(ptr_list);
	if (max_num == 0)
		return (1); // 0の場合、桁数は1
    while (max_num > 0)
	{
        bit_len++;
        max_num /= 2; // 2で割りながら桁数をカウント
    }
    return (bit_len);
}