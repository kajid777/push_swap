/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:07:18 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/17 15:14:29 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(Node *list_top)
{
	Node*	current_node;
	int count;

	count = 0;
	if (list_top == NULL)
	{
		return (0);
	}
	current_node = list_top;
	ft_printf("%d\n", current_node->data_num);
	current_node = current_node->next;
	count++;
	while (current_node != list_top)
	{
		ft_printf("%d\n", current_node->data_num);
		count++;
		current_node = current_node->next;
	}
	return (count);
}
