#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int n);
void merge(int *arr, int *L, int nL, int *R, int nR);

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
    merge_sort(arr, n);
    printf("After sorting the array is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void merge_sort(int *arr, int n)
{
    if (n < 2) return;
    int mid = n/2;
    int nL = mid;
    int nR = n - mid;
    int *L = (int*)malloc(sizeof(int)*nL);
    int *R = (int*)malloc(sizeof(int)*nR);
    for (int i = 0; i < nL; i++) L[i] = arr[i];
    for (int i = mid; i < n; i++) R[i-mid] = arr[i];
    merge_sort(L, nL);
    merge_sort(R, nR);
    merge(arr, L, nL, R, nR);
    free(L);
    free(R);
}

void merge(int *arr, int *L, int nL, int *R, int nR)
{
    int l, r, a;
    l = r = a= 0;
    while ((l<nL) && (r<nR))
    {
        if (L[l] < R[r]) arr[a++] = L[l++];
        else arr[a++] = R[r++];
    }
    while (l<nL) arr[a++] = L[l++];
    while (r<nR) arr[a++] = R[r++];
}