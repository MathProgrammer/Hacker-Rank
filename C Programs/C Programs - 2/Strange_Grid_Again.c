#include <stdio.h>

int main()
{
    long row, column, number;
    scanf("%ld %ld", &row, &column);

    number = 2*(column - 1) + ( (row - 1)/2 )*10 + (row - 1)%2;

    printf("%ld\n",number);
    return 0;
}
