/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:37:18 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/01 16:14:54 by dkajiwar         ###   ########.fr       */
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

void	sort_3(Node **stack)
{
	int		pattern_id;

	pattern_id = pattern_identify_x(stack);
	// ft_printf("test:pattern_id:%d\n" ,pattern_id);
	if (is_sorted(stack))
		return ;
	if (pattern_id == 1)
		sort_3_mod_1(stack);
	else if (pattern_id == 2)
		sort_3_mod_2(stack);
	else if (pattern_id == 3)
		sort_3_mod_3(stack);
	else if (pattern_id == 4)
		sort_3_mod_4(stack);
	else if (pattern_id == 5)
		sort_3_mod_5(stack);
	return;
}

void	sort_4(Node **stack_a, Node **stack_b)
{
	int		pattern_id;

	// ft_printf("min_num;%d\n", get_min_num(*stack_a));
	
	if (is_sorted(stack_a))
		return ;
	pattern_id = pattern_identify_y(stack_a, get_min_num(*stack_a));
	// ft_printf("pattern_id_sort_4:%d\n", pattern_id);
	
	if (pattern_id == 1)
		sort_4_mod_1(stack_a, stack_b);
	else if (pattern_id == 2)
		sort_4_mod_2(stack_a, stack_b);
	else if (pattern_id == 3)
		sort_4_mod_3(stack_a, stack_b);
	else if (pattern_id == 4)
		sort_4_mod_4(stack_a, stack_b);
	return;
}

void	sort_5(Node **stack_a, Node **stack_b)
{
	int		pattern_id;

	// ft_printf("min_num;%d\n", get_min_num(*stack_a));
	
	if (is_sorted(stack_a))
		return ;
	pattern_id = pattern_identify_y(stack_a, get_min_num(*stack_a));
	// ft_printf("pattern_id_sort_5:%d\n", pattern_id);
	
	if (pattern_id == 1)
		sort_5_mod_1(stack_a, stack_b);
	else if (pattern_id == 2)
		sort_5_mod_2(stack_a, stack_b);
	else if (pattern_id == 3)
		sort_5_mod_3(stack_a, stack_b);
	else if (pattern_id == 4)
		sort_5_mod_4(stack_a, stack_b);
	else if (pattern_id == 5)
		sort_5_mod_5(stack_a, stack_b);
	return;
}

void	simple_sort(Node **stack_a, Node **stack_b)
{
	int	size;

	(void)stack_b;
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
