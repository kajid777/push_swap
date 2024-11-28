/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:07:18 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/28 19:14:36 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(Node *list_top)
{
	Node*	current_node;
	int		count;

	count = 0;
	if (list_top == NULL)
	{
		return (0);
	}
	current_node = list_top;
	current_node = current_node->next;
	count++;
	while (current_node != list_top)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}
// ft_printf("%d\n", current_node->data_num);
// ft_printf("%d\n", current_node->data_num);

int	is_sorted(Node **stack)
{
	Node	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->data_num > head->next->data_num)
		{
			
			return (0);
			
		}
		head = head->next;
	}

	return (1);
}

int	get_distance(Node **stack, int data_num)
{
	Node	*head;
	int		distance;

	distance = 0;
	head = *stack;
	
	while (head)
	{

		if (head->data_num == data_num)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
