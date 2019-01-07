#include <stdio.h>
#include <stdlib.h>

int lcm(int *arr, int arr_count);
int gcd(int i, int j);

int main(void)
{
    printf("Enter the number of elements you will pass : ");
    int n;
    scanf("%d", &n);
    printf("Enter %d elements separated by spaces : ", n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("The lcm of the entered number is %d\n", lcm(arr, n));
    return 0;
}

int gcd(int i, int j)
{
    if (j == 0) return i;
    else return gcd(j, i%j);
}

int lcm(int *arr, int arr_count)
{
    int ans = arr[0];
    for (int i = 1; i < arr_count; i++)
    {
        ans = (ans*arr[i])/gcd(ans, arr[i]);
    }
    return ans;
}