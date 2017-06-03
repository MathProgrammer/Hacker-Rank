#include <stdio.h>

int main()
{
    int no_of_numbers, no_of_positive_numbers = 0, no_of_zeroes = 0, no_of_negative_numbers = 0, i, number;
    float positive_fraction, negative_fraction, zero_fraction;
    scanf("%d", &no_of_numbers);

    for(i = 1; i <= no_of_numbers; i++)
    {
        scanf("%d",&number);

        if(number > 0) no_of_positive_numbers++;
        else if(number == 0) no_of_zeroes++;
        else if(number < 0) no_of_negative_numbers++;
    }

    positive_fraction = (no_of_positive_numbers*1.0)/no_of_numbers;
    negative_fraction = (no_of_negative_numbers*1.0)/no_of_numbers;
    zero_fraction = (no_of_zeroes*1.0)/no_of_numbers;

    printf("%.6f\n%.6f\n%.6f\n",positive_fraction, negative_fraction, zero_fraction);
    return 0;
}
