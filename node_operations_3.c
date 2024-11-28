/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:34:47 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/27 18:50:04 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(Node **topoflist_a)
{
	if (*topoflist_a == NULL)
		return;
	*topoflist_a = (*topoflist_a)->prev;
	return;
}

void rrb(Node **topoflist_b)
{
	if (*topoflist_b == NULL)
		return;
	*topoflist_b = (*topoflist_b)->prev;
	return;
}

void rrr(Node **topoflist_a, Node **topoflist_b)
{
	rra(topoflist_a);
	rrb(topoflist_b);
}
