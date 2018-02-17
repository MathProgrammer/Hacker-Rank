#include <cstdio>

long long power(long long x, long long pow, int MOD)
{
    long long result = 1;

    while(pow)
    {
        if(pow%2 == 1)
            result = (result*x)%MOD;

        x = (x*x)%MOD;
        pow = pow >> 1;
    }

    return result;
}

void solve()
{
    long long length, no_of_alphabets;
    scanf("%lld %lld", &length, &no_of_alphabets);

    const int MOD = 1e9 + 7;
    long long answer = 1;

    if(length == 1) answer = no_of_alphabets%MOD;
    else answer = ( ( ( no_of_alphabets*(no_of_alphabets - 1) )%MOD )*power(no_of_alphabets - 2, length - 2, MOD) )%MOD;

    printf("%lld\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
