#include <stdio.h>

#define NUMBER_SIZE 50
#define MAX_NUMBERS 10000 + 1

int main()
{
    int sum[2*NUMBER_SIZE] = {0}; //The sum is set to have about twice the number of digits as each number
    int i, row, column, matrix[MAX_NUMBERS][NUMBER_SIZE], no_of_numbers;
    int column_sum, first_digit, carry = 0;
    const int base = 10, desired_digits = 10;

    scanf("%d", &no_of_numbers);
    for(row = 0; row < no_of_numbers; row++)
        for(column = 0; column < NUMBER_SIZE; column++)
            scanf("%1d",&matrix[row][column]);

    first_digit = 2*NUMBER_SIZE - 1;
    for(column = NUMBER_SIZE - 1; column >= 0; column--)
    {
        column_sum = 0;
        for(row = 0; row < no_of_numbers; row++)
            column_sum += matrix[row][column];

        sum[first_digit--] = (column_sum + carry)%base;
        carry = (column_sum + carry)/base;
    }

    while(carry != 0)
    {
        sum[first_digit--] = carry%base;
        carry = carry/base;
    }

    //sum[first_digit] = 0, the last digit has been placed in sum[first_digit + 1]
    for(i = first_digit + 1; i <= first_digit + desired_digits; i++)
        printf("%d",sum[i]);

    return 0;
}

