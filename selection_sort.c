#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int n);

int *max(int *arr, int n)
{
    int max = arr[0], count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (max < arr[i])
        {
            max = arr[count = i];
        }
    }
    return (arr + count);
}

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
    selection_sort(arr, n);
    printf("After sorting the array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void selection_sort(int *arr, int n)
{
    int end = n-1;
    while (end >= 0)
    {
        swap(&arr[end], max(arr, end));
        end--;
    }
}