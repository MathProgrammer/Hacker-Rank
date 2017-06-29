#include <cstdio>

void solve()
{
    long long n, reduced_n;
    scanf("%lld", &n);

    reduced_n = n;
    long long largest_prime_factor;

    for(long long i = 2; i*i <= n; i++)
    {
        if(reduced_n%i == 0)
        {
            largest_prime_factor = i;
            while(reduced_n%i == 0)
            {
                reduced_n /= i;
            }
        }
    }

    if(reduced_n > 1)
        largest_prime_factor = reduced_n;

    printf("%lld\n", largest_prime_factor);

}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}


