#include <cstdio>

int sum_of_digits(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum += n%10;
        n = n/10;
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int original_n = n;
    int sum_of_prime_factors_digit = 0;

    for(int i = 2; i*i <= n; i++)
    {
        int exponent = 0;

        while(n%i == 0)
        {
            n = n/i;
            exponent++;
        }

        sum_of_prime_factors_digit += exponent*sum_of_digits(i);
    }

    if(n > 1)
        sum_of_prime_factors_digit += sum_of_digits(n);

    printf("%d\n", sum_of_digits(original_n) == sum_of_prime_factors_digit ? 1 : 0);
    return 0;
}
