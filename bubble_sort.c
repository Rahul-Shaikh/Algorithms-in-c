#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n);
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
    bubble_sort(arr, n);
    printf("After sorting the array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void bubble_sort(int *arr, int n)
{
    for (int i = 1;i < n;i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j+1]);
        }
    }
}