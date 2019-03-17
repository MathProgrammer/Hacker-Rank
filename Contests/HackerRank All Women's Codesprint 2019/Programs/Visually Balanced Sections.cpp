#include <cstdio>
#include <vector>
#include <map>
#include <ctime>
#include <iostream>

typedef long long LL;

using namespace std;

void solve()
{
    int length;
    scanf("%d", &length);

    const int MAX_COLOUR = 50;
    vector <LL> colour(length + 1);
    for(int i = 1; i <= length; i++)
    {
        int x;
        scanf("%d", &x);

        colour[i] = (1LL << x);
    }

    LL good_segments = 0;
    LL prefix_xor = 0;
    map <LL, int> prefix_xor_frequency;

    prefix_xor_frequency[prefix_xor] = 1;

    for(int i = 1; i <= length; i++)
    {
        prefix_xor ^= colour[i];

        for(int c = 1; c <= MAX_COLOUR; c++)
        {
            LL standing_out_colour = (1LL << c);

            LL required_xor = prefix_xor^standing_out_colour;

            good_segments += prefix_xor_frequency[required_xor];
        }

        good_segments += prefix_xor_frequency[prefix_xor];

        prefix_xor_frequency[prefix_xor]++;
    }

    printf("%lld\n", good_segments);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
