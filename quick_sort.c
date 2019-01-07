#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
int r_partition(int *arr, int start, int end);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{
    int n;
    printf("Enter the number of elements you will enter : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Your entered array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    quick_sort(arr, 0, n-1);
    printf("After sorting the array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void quick_sort(int *arr, int start, int end)
{
    if (start >= end) return;
    int p_index = r_partition(arr, start, end); 
    quick_sort(arr, start, p_index-1);
    quick_sort(arr, p_index+1, end);
}

int r_partition(int *arr, int start, int end)
{
    srand(time(NULL));
    int random = start + rand()%(end - start);
    swap(&arr[end], &arr[random]);
    return partition(arr, start, end);
}

int partition(int *arr, int start, int end)
{
    int p = arr[end];
    int p_index = start;
    for (int i = start; i <= end - 1; i ++)
    {
        if (arr[i] <= p)
        {
            swap(&arr[i], &arr[p_index++]);
        }
    }
    swap(&arr[p_index], &arr[end]);
    return p_index;
}