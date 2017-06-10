#include <stdio.h>

#define min(a, b) (a < b ? a : b)

int sum_digits(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

int check_which_is_better(int a, int b)
{
     int a_digit_sum = sum_digits(a), b_digit_sum = sum_digits(b);

    if(a_digit_sum > b_digit_sum)
        return a;
    else if(a_digit_sum < b_digit_sum)
        return b;
    else
        return min(a, b);
}

int main()
{
    int i, n, best_divisor = 0;
    scanf("%d", &n);

    for(i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            best_divisor = check_which_is_better(best_divisor, i);
            best_divisor = check_which_is_better(best_divisor, n/i);
        }
    }

    printf("%d\n",best_divisor);
    return 0;
}
