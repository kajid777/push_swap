/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:46 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/02 14:59:24 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int contains_invalid_char(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
            return 1; // 数字とスペース以外の文字が見つかった場合
        }
        i++;
    }
    return 0; // 有効な文字のみの場合
}

void end_with_error()
{
	ft_printf("Error\n");
	exit(1);
}
