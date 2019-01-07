#include <stdio.h>

int gcd(int i, int j)
{
    if (j == 0) return i;
    else return gcd(j, i%j);
}

int main(void)
{
    int i, j;
    printf("Enter the two numbers: ");
    scanf("%d%d", &i, &j);
    printf("\nThe gcd of %d and %d is %d\n", i, j, gcd(i, j));
    return 0;
}