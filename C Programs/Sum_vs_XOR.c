#include <stdio.h>

int main()
{
    unsigned long long number, answer;
    int no_of_zero_bits = 0;

    scanf("%I64u",&number);

    while(number!= 0ULL)
    {
        if( (number & 1ULL) == 0)
        {
            no_of_zero_bits++;
        }

        number = number >> 1;
    }

    //Copy n in binary form, writing a 0 wherever n has a 1 and writing an x wherever there is a 0. Any binary combination of the x's gives a number
    //n + x = n XOR x
    //Because there are no bits set in the same position, hence addition will have no carry.
    answer = 1ULL << no_of_zero_bits; //Remember to explicitly typecast. Otherwise, truncation error occurs because 1 is treated like an int.

    printf("%I64u\n",answer);
    return 0;
}
