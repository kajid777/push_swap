/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:07:18 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/29 12:24:34 by dkajiwar         ###   ########.fr       */
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

int pattern_identify_mod(int a, int b, int c)
{
	if (a > b)
	{
		if (a < c)
			return (2);
		else
		{
			if (b < c)
				return (4);
			else
				return (5);
		}
	}
	else
	{
		if (a < c)
			return (1);
		else
			return (3);	
	}
}
int pattern_identify(Node **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->data_num;
	ft_printf("a:%d\n", a);
	b = (*stack)->next->data_num;
	ft_printf("b:%d\n", b);
	c = (*stack)->next->next->data_num;
	ft_printf("c:%d\n", c);

	
	return (pattern_identify_mod(a, b, c));
}



int	is_sorted(Node **stack)
{
	Node*	Node_to_be_compared;

	if (*stack == NULL)
	{
		ft_printf("this stack has nothing.\n");
		return (1);
	}
	Node_to_be_compared = *stack;
	if (Node_to_be_compared->data_num > Node_to_be_compared->next->data_num)
		return (0);
	Node_to_be_compared = Node_to_be_compared->next;
	while (Node_to_be_compared->next != *stack)
	{
		if (Node_to_be_compared->data_num > Node_to_be_compared->next->data_num)
		return (0);
		Node_to_be_compared = Node_to_be_compared->next;
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
