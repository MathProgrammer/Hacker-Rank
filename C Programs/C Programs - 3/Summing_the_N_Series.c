#include <stdio.h>

void solve()
{
    const int MOD = 1e9 + 7;
    long long n, ans;
    scanf("%lld",&n);

    n = (n%MOD);
    ans = (n*n)%MOD;

    printf("%lld\n",ans);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
