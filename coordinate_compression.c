#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int arr_size)
{
 	// int size;

	// size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arr_size - 1; i++) {
        int min_index = i; // 現在の位置を最小インデックスとして初期化
        for (int j = i + 1; j < arr_size; j++) {
            // 未ソート部分から最小の要素のインデックスを見つける
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // 最小値を現在の位置と交換
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
int *copy_array(int *arr, int arr_size)
{
    // int arr_size;
	int i;
	int	*copied_array;

	// arr_size = sizeof(arr) / sizeof(arr[0]);
	copied_array = (int*)malloc(sizeof(int) * arr_size);
	if (copied_array == NULL)
		return (NULL);
	i = 0;
	while(i < arr_size)
	{
		copied_array[i] = arr[i];
		i++;
	}
	return (copied_array);
}

int index_finder(int *copied_arr, int arr_size, int num)
{
	int	index;
	// int arr_size;

	// arr_size = sizeof(arr) / sizeof(arr[0]);

	index = 0;
	while (index < arr_size)
	{
		if (num == copied_arr[index])
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

void	set_coordinate(int *arr, int *copied_arr, int *dest_arr, int arr_size)
{
	// int arr_size;
	int i;

	i = 0;
	// arr_size = sizeof(copied_arr) / sizeof(copied_arr[0]);
	selection_sort(copied_arr, arr_size);
    printf("sorted_array:");
	for (int i = 0; i < arr_size; i++) {
        printf("%d ", copied_arr[i]);
    }
	while(i < arr_size)
	{
		dest_arr[i] = index_finder(copied_arr, arr_size, arr[i]);
		i++;
	}
	return;
}

int *coordinate_compression(int *arr, int arr_size)
{
	int	*dest_arr;
	int	*copied_arr;

    // int arr_size;

	// arr_size = sizeof(arr) / sizeof(arr[0]);

	copied_arr = copy_array(arr, arr_size);
	if (copied_arr == NULL)
		return (NULL);
	printf("copied_array:");
	for (int i = 0; i < arr_size; i++) {
        printf("%d ", copied_arr[i]);
    }
	dest_arr = (int*)malloc(sizeof(int) * arr_size);
	if (dest_arr == NULL)
		return (NULL);
	set_coordinate(arr, copied_arr, dest_arr, arr_size);
	free(arr);
	free(copied_arr);
	return (dest_arr);
}
// 使用例
// int main() {
//     // int arr[] = {4, -167, -351, 298, -22, 251};
//     int arr[] = {-111, 2, 3, 1, 5, -1111, 8, 19090, 6};


//     // int compressed_size;
// 	int arr_size = sizeof(arr) / sizeof(arr[0]);

//     int *compressed = coordinate_compression(arr, arr_size);
//     printf("Compressed array: ");
//     for (int i = 0; i < arr_size; i++) {
//         printf("%d ", compressed[i]);
//     }
//     printf("\n");

//     free(compressed);
//     return 0;
// }
