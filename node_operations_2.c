/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:31:29 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/27 18:32:03 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(Node **topoflist_a)
{
	if (*topoflist_a == NULL)
		return;
	*topoflist_a = (*topoflist_a)->next;
	ft_printf("ra\n");
	return;
}

void rb(Node **topoflist_b)
{
	if (*topoflist_b == NULL)
		return;
	*topoflist_b = (*topoflist_b)->next;
	ft_printf("rb\n");
	return;
}

void rr(Node **topoflist_a, Node **topoflist_b)
{
	ra(topoflist_a);
	rb(topoflist_b);
}