/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:55:19 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/01 16:04:01 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5_mod_1(Node **stack_a, Node **stack_b)
{
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

void sort_5_mod_2(Node **stack_a, Node **stack_b)
{
	ft_printf("ra\n");
	ra(stack_a);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

void sort_5_mod_3(Node **stack_a, Node **stack_b)
{
	ft_printf("ra\n");
	ra(stack_a);
	ft_printf("ra\n");
	ra(stack_a);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

void sort_5_mod_4(Node **stack_a, Node **stack_b)
{
	ft_printf("rra\n");
	rra(stack_a);
	ft_printf("rra\n");
	rra(stack_a);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

void sort_5_mod_5(Node **stack_a, Node **stack_b)
{
	ft_printf("rra\n");
	rra(stack_a);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

