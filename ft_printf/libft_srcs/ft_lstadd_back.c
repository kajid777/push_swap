/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:57:07 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/10/26 17:28:00 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dest;

	if (!new)
		return ;
	if (!lst[0])
		lst[0] = new;
	else
	{
		dest = ft_lstlast(lst[0]);
		dest->next = new;
	}
}
//Is lst[0] same as *lst?
