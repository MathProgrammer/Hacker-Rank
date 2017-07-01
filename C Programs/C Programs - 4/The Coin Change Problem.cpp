#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int sum, no_of_coins;
    scanf("%d %d", &sum, &no_of_coins);

    vector <int> coin_value(no_of_coins + 1, 0); //Put an additional 0 coin so that it is 1-indexed
    for(int i = 1; i <= no_of_coins; i++)
        scanf("%d",&coin_value[i]);

    sort(all(coin_value));

    vector <long long> no_of_ways_to_make(sum + 1);

    no_of_ways_to_make[0] = 1;
    for(int coin_no = 1; coin_no <= no_of_coins; coin_no++)
    {
        for(int sum_reached = coin_value[coin_no]; sum_reached <= sum; sum_reached++)
        {
            //f(i, j) = f(i, j - 1) + f(i - value[j], j) ... Here it already contains f(i, j - 1) so we add the required amount
            no_of_ways_to_make[sum_reached] += no_of_ways_to_make[sum_reached - coin_value[coin_no]];
        }
    }

    printf("%lld\n",no_of_ways_to_make[sum]);
    return 0;
}

