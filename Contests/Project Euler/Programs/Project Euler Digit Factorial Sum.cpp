#include <cstdio>

void precompute(int factorial[], int LIMIT)
{
    factorial[0] = 1;
    for(int i = 1; i < LIMIT; i++)
        factorial[i] = i*factorial[i - 1];
}

int digit_factorial_sum(int n, int factorial[])
{
    int sum = 0;

    while(n)
    {
        sum += factorial[n%10];
        n /= 10;
    }

    return sum;
}

int main()
{
    int N;
    scanf("%d", &N);

    const int LIMIT = 10;
    int factorial[LIMIT];
    precompute(factorial, LIMIT);

    int sum = 0;
    for(int i = 10; i < N; i++)
    {
        sum += i*(digit_factorial_sum(i, factorial)%i == 0);
    }

    printf("%d\n", sum);
    return 0;
}
