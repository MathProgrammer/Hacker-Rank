#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7, LIMIT = 1001;
int factorial[LIMIT];

void precompute_factorial()
{
    factorial[0] = factorial[1] = 1;

    for(int i = 2; i < LIMIT; i++)
        factorial[i] = (factorial[i - 1]*1LL*i)%MOD;
}

long long power(int x, int power)
{
    long long result = 1, y = x;

    while(power)
    {
        if(power%2 == 1)
            result = (result*y)%MOD;

        y = (y*y)%MOD;
        power = power >> 1;
    }

    return result;
}

int inverse(int n)
{
    return power(n, MOD - 2);
}

int combinations(int n, int r)
{
    int numerator = factorial[n];
    int denominator = (factorial[r]*1LL*factorial[n - r])%MOD;

    return (numerator*1LL*inverse(denominator)%MOD);
}

int main()
{
    precompute_factorial();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        printf("%d\n", combinations(m + n, m));
    }

    return 0;
}

