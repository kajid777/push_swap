/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:25:45 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/01 15:41:22 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_4_mod_1(Node **stack_a, Node **stack_b)
{
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_3(stack_a);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

void sort_4_mod_2(Node **stack_a, Node **stack_b)
{
	ft_printf("ra\n");
	ra(stack_a);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_3(stack_a);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

void sort_4_mod_3(Node **stack_a, Node **stack_b)
{
	ft_printf("ra\n");
	ra(stack_a);
	ft_printf("ra\n");
	ra(stack_a);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_3(stack_a);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}

void sort_4_mod_4(Node **stack_a, Node **stack_b)
{
	ft_printf("rra\n");
	rra(stack_a);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	sort_3(stack_a);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	return;
}
