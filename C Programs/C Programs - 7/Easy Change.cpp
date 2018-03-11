#include <bits/stdc++.h>

using namespace std;

int is_possible(int n)
{
    return (n == 1000 || n == 500 || n == 200 || n == 100 || n == 50 || n == 20);
}

void solve()
{
    int price, paid;
    scanf("%d %d", &price, &paid);

    int difference = paid - price;

    for(int i = 0; i <= 9; i++)
    {
        if(is_possible(difference + i))
        {
            printf("%d\n", i);
            return;
        }
    }

    printf("-1\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
