/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:05:39 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 18:06:04 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (64 < c && c < 91)
	{
		c += 32;
	}
	return (c);
}

// int main(){
// 	char x;
//     printf("一文字を入力してください: ");
//     scanf("%c", &x);

//     x = ft_tolower(x);
//     printf("%c が関数での処理を施した後の文字です。\n", x);

//     return 0;
// }