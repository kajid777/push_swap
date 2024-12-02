/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:15:47 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/12/02 15:00:35 by dkajiwar         ###   ########.fr       */
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

// int_arrayの中身を出力する関数
// void print_int_array(int *array, size_t size) {
//     if (array == NULL) {
//         printf("The array is NULL.\n");
//         return;
//     }
//     printf("int_array contents:\n");
//     for (size_t i = 0; i < size; i++) {
//         printf("int_array[%zu] = %d\n", i, array[i]);
//     }
// }

int *convert_to_int_array(char **str_array, int *size)
{
    int count = 0;
    int i;

    // 配列のサイズを数える
    while (str_array[count] != NULL) {
        count++;
    }
    *size = count;
    // int型配列を確保
    int *int_array = (int *)malloc(sizeof(int) * count);
    if (int_array == NULL)
    {
        free_segments(str_array);
        end_with_error();
    }
    // 各文字列をintに変換
    i = 0;
    while (i < count)
    {
        int_array[i] = ft_atoi(str_array[i]);
        i++;
    }
    return int_array;
}
Node*   make_list_y(const char *str)
{
    Node    *topoflist;
    int     i;
    int     arr_size;
    int *int_array;
    int *compressed_array;

    topoflist = NULL;
    i = 0;
    
    int_array = convert_to_int_array(ft_split(str, ' '), &arr_size);
    // print_int_array(int_array, arr_size);
    if (int_array == NULL)
        end_with_error();
    compressed_array = coordinate_compression(int_array, arr_size);
    if (compressed_array == NULL)
        end_with_error();
    while (i < arr_size)
    {
        append_node_from_back(&topoflist, create_node(compressed_array[i]));
        i++;
    }
    free(compressed_array);
    return (topoflist);
}

Node*   make_list_x(int argc, int *int_arr)
{
    Node    *topoflist;
    Node    *ptr_new_node;
    int     i;

    if (int_arr == NULL)
        return NULL;
    i = 0;
    topoflist = NULL;
    while(i < argc - 1)
    {
        ptr_new_node = create_node(int_arr[i]);
        if (ptr_new_node == NULL)
        {
            free_all_nodes(topoflist);
            free(int_arr);
		    end_with_error();
        }
        append_node_from_back(&topoflist, ptr_new_node);
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
    if (argc == 2)
    {
        if (contains_invalid_char(argv[1]))
            end_with_error();
        topoflist_a = make_list_y(argv[1]);
        // print_all_node(topoflist_a);
        sort(&topoflist_a, &topoflist_b);
        // print_all_node(topoflist_a);
        return (0);
    }
    topoflist_a = make_list_x(argc, create_int_array(argc, argv));
    // print_all_node(topoflist_a);
    sort(&topoflist_a, &topoflist_b);
    // print_all_node(topoflist_a);
    free_all_nodes(topoflist_a);
    return (0);
}
// ft_printf("test1\n");
// ft_printf("after sort\n");
// ft_printf("stack a\n");
// print_all_node(topoflist_a);
// ft_printf("stack b\n");
// print_all_node(topoflist_b);
