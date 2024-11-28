/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:37:18 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/28 19:15:31 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	get_min(Node **stack, int val)
// {
// 	Node	*head;
// 	int		min;

// 	head = *stack;
// 	min = head->data_num;
// 	while (head->next)
// 	{
//         ft_printf("test\n");

// 		head = head->next;
// 		if ((head->data_num < min) && head->data_num != val)
// 			min = head->data_num;
// 	}
// 	return (min);
// }
int get_min_num(Node *ptr_list)
{
	int min;
	Node	*Node_to_be_compared;
	if (ptr_list == NULL)
	{
		return (-1);
	}
	Node_to_be_compared = ptr_list;
	min = Node_to_be_compared->data_num;
	Node_to_be_compared = Node_to_be_compared->next;
	while (Node_to_be_compared != ptr_list)
	{
		if (min > Node_to_be_compared->data_num)
		{
			min = Node_to_be_compared->data_num;
		}
		Node_to_be_compared = Node_to_be_compared->next;
	}
	return (min);
}
void	sort_3(Node **stack_a)
{
	Node	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->data_num == min && head->next->data_num != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->data_num == next_min)
	{
		if (head->next->data_num == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->data_num == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort_4(Node **stack_a, Node **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min_num(*stack_a));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(Node **stack_a, Node **stack_b)
{
	int	distance;
	
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(Node **stack_a, Node **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || get_stack_size(*stack_a) == 0
		|| get_stack_size(*stack_a) == 1)
		return ;
	size = get_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}