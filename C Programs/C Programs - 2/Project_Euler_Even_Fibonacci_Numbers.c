#include <stdio.h>
#include <stdlib.h>
#define SIZE 83

int main()
{
    int i, no_of_test_cases;
    unsigned long long sum_even_fibo_till_fibo[SIZE] = {0},fibo[SIZE], upper_limit;

    //Building an array of Fibonacci numbers
    fibo[0] = 0;
    fibo[1] = 1;
    sum_even_fibo_till_fibo[0] = sum_even_fibo_till_fibo[1] = 0;
    for(i = 2; i < SIZE ;i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];

        //If i is a multiple of 3, Fibo[i] is even
        sum_even_fibo_till_fibo[i] = (i%3 == 0 ? sum_even_fibo_till_fibo[i-1] + fibo[i] : sum_even_fibo_till_fibo[i - 1]);
    }

    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
    {
        scanf("%llu",&upper_limit);

        for(i = 0; fibo[i] <= upper_limit; i++);

        printf("%llu\n",sum_even_fibo_till_fibo[i-1]);
    }

    return 0;
}
