/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:15:47 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/11/11 17:42:43 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

static void	free_segments(char **segments)
{
	int	i;

	i = 0;
	while (segments[i] != 0)
	{
		free(segments[i]);
		i++;
	}
	free(segments);
}

Node*   make_list_a(const char *str)
{
    Node    *topoflist;
    char    **split_nums;
    int     i;

    topoflist = NULL;
    i = 0;
    split_nums = ft_split(str, ' ');
    while(split_nums[i] != NULL)
    {
        append_node(&topoflist, create_node(ft_atoi(split_nums[i])));
        i++;
    }
    free_segments(split_nums);
    return (topoflist);
}
// print_all_node(topoflist);

Node*   make_list_x(int argc, int *int_arr)
{
    Node    *topoflist;
    Node    *ptr_new_node;
    int     i;

    if (int_arr == NULL) // NULLチェック
    {
        return NULL;
    }
    i = 0;
    topoflist = NULL;
    while(i < argc - 1)
    {
        ptr_new_node = create_node(int_arr[i]);
        if (ptr_new_node == NULL)
            free_all_nodes(topoflist);
        append_node(&topoflist, ptr_new_node);
        i++;
    }
    return (topoflist);
}

int main(int argc, char **argv)
{
    Node *topoflist_a;
    Node *topoflist_b;


    topoflist_a = NULL;
    topoflist_b = NULL;
    // if (argc < 2)
    // 	return (-1);
    // if (argc == 2)
    // {
    //     topoflist = make_list_a(argv[1]);
    // }
    // if (argc >= 3)
    // {
    topoflist_a = make_list_x(argc, create_int_array(argc, argv));
    ft_printf("before sort\n");
    print_all_node(topoflist_a);
    sort(&topoflist_a, &topoflist_b);
    ft_printf("after sort\n");
    ft_printf("stack a\n");
    print_all_node(topoflist_a);
    ft_printf("stack b\n");
    print_all_node(topoflist_b);

    return (0);
}