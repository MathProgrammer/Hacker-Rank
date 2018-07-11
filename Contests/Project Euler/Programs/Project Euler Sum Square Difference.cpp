#include <cstdio>

void solve()
{
    int n;
    scanf("%d", &n);

    long long sum = (n*1LL*(n + 1)) >> 1;
    sum = sum*sum;
    long long square_sum = (n*1LL*(n + 1)*(2*n + 1))/6;

    printf("%lld\n", sum - square_sum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
