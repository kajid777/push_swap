/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:30:32 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/29 12:13:18 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_mod_1(Node **stack)
{
	ft_printf("rra\n");
	rra(stack);
	ft_printf("sa\n");
	sa(stack);
	return;
}

void sort_3_mod_2(Node **stack)
{
	ft_printf("sa\n");
	sa(stack);
	return;
}

void sort_3_mod_3(Node **stack)
{
	ft_printf("rra\n");
	rra(stack);
	return;
}

void sort_3_mod_4(Node **stack)
{
	ft_printf("ra\n");
	ra(stack);
	return;
}

void sort_3_mod_5(Node **stack)
{
	ft_printf("test:5\n");
	ft_printf("sa\n");
	sa(stack);
	ft_printf("rra\n");
	rra(stack);
	return;
}
