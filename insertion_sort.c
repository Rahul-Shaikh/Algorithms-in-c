#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n);

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
    insertion_sort(arr, n);
    printf("After sorting the array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int hole = i;
        while ((hole > 0) && (arr[hole-1] > value))
        {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
}