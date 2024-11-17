/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:47:34 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/15 16:09:46 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(Node **ptr_topoflist_a, Node **ptr_topoflist_b)
{
	int max_bit_len;

	max_bit_len = get_max_bit_len(*ptr_topoflist_a);
	(void)ptr_topoflist_b;
	ft_printf("test:max:%d\n", max_bit_len);
}