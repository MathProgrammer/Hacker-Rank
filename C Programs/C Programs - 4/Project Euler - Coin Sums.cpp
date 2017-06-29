#include <cstdio>
#include <vector>

using namespace std;

vector <vector <long long> > no_of_ways_to_make(1e5 + 1, vector <long long> (8 + 1, 0));

void precompute_coin_sums()
{
    const int MOD = 1e9 + 7;
    int coin_value[8 + 1] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

    for(int coin_no = 1; coin_no <= 8; coin_no++)
    {
        no_of_ways_to_make[0][coin_no] = 1;
    }

    for(int coin_no = 1; coin_no <= 8; coin_no++)
    {
        for(int sum_reached = 1; sum_reached <= 1e5; sum_reached++)
        {
            if(sum_reached >= coin_value[coin_no])
            {
                no_of_ways_to_make[sum_reached][coin_no] = (no_of_ways_to_make[sum_reached][coin_no - 1]//Don't use coin i

                                                            + no_of_ways_to_make[sum_reached - coin_value[coin_no] ][coin_no])%MOD; //Use coin i
            }
            else
            {
                no_of_ways_to_make[sum_reached][coin_no] = no_of_ways_to_make[sum_reached][coin_no - 1];
            }
        }
    }
}

void solve()
{
    int sum;
    scanf("%d", &sum);

    printf("%lld\n",no_of_ways_to_make[sum][8]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_coin_sums();

    while(no_of_test_cases--)
        solve();

    return 0;
}
