/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:26:55 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/27 18:54:55 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_num(Node *ptr_list)
{
	int max;
	Node	*Node_to_be_compared;
	if (ptr_list == NULL)
	{
		return (-1);
	}
	Node_to_be_compared = ptr_list;
	max = Node_to_be_compared->data_num;
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
//ft_printf("this list has nothing.");
//ft_printf("%d\n", Node_to_be_compared->data_num);



int	get_max_bit_len(Node *ptr_list)
{
	int	bit_len;
	int	max_num;

	bit_len = 0;
	max_num = get_max_num(ptr_list);
	if (max_num == 0)
		return (1);
	while (max_num > 0)
	{
		bit_len++;
		max_num /= 2;
	}
	return (bit_len);
}
// 0の場合、桁数は1
// 2で割りながら桁数をカウント