#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int gcd(long long a, long long b)
{
    if(a == 0 || b == 0)
        return (a + b);

    return gcd(min(a, b), max(a, b)%min(a, b));
}
void solve()
{
    int no_of_coins;
    scanf("%d", &no_of_coins);

    vector <long long> coin(no_of_coins + 1, 0);
    for(int i = 1; i <= no_of_coins; i++) scanf("%lld", &coin[i]);

    if(no_of_coins == 1)
    {
        printf("%lld\n", coin[1]);
        return;
    }

    sort(all(coin));

    long long numerator = 0, denominator = 6;

    for(int i = 1; i <= no_of_coins; i++) numerator += coin[i]*(i == 1 || i == no_of_coins ? 3 : 2);

    int gcd_fraction = gcd(numerator, denominator);
    numerator /= gcd_fraction;
    denominator /= gcd_fraction;

    if(denominator == 1)
        printf("%lld\n", numerator);
    else
        printf("%lld/%lld\n", numerator, denominator);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

