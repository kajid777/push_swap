#include "push_swap.h"

#include <stdio.h>

int has_duplicates(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while(j < size)
        {
            if (arr[i] == arr[j])
            {
                ft_printf("Error: Duplicate value %d found at indices %d and %d\n", arr[i], i, j);
                return (1);
            }
            j++;
        }
        i++;
    }
    ft_printf("No duplicates found.\n");

    return (0);
}

Node *free_all_nodes(Node *topoflist)
{
    Node *ptr_node_to_be_cleared;
    Node *tmp;
    // Node *topoflist;

    if (topoflist == NULL)
        return (NULL);
    ptr_node_to_be_cleared = topoflist->prev;
    while(ptr_node_to_be_cleared != topoflist)
    {
        tmp = ptr_node_to_be_cleared->prev;
        free(ptr_node_to_be_cleared);
        ptr_node_to_be_cleared = tmp;
    }
    free(ptr_node_to_be_cleared);
    return(topoflist);
    //pay attention to double free!!!
}