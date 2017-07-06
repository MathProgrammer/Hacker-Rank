#include <cstdio>

using namespace std;

void solve()
{
    int no_of_cuts;
    scanf("%d", &no_of_cuts);

    int horizontal_cuts = no_of_cuts/2;
    int vertical_cuts = no_of_cuts - no_of_cuts/2;

    printf("%lld\n", horizontal_cuts*1LL*vertical_cuts);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

