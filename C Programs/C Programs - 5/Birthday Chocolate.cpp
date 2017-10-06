#include <bits/stdc++.h>

using namespace std;

int main()
{
    int no_of_pieces;
    scanf("%d", &no_of_pieces);

    vector <int> chocolate(no_of_pieces + 1);
    for(int i = 1; i <= no_of_pieces; i++)
        scanf("%d", &chocolate[i]);

    int block_size, sum;
    scanf("%d %d", &sum, &block_size);

    int current_block_sum = 0, no_of_ways = 0;
    for(int i = 1; i <= no_of_pieces; i++)
    {
        current_block_sum += (i <= block_size ? chocolate[i] : chocolate[i] - chocolate[i - block_size]);
        no_of_ways += (current_block_sum == sum && i >= block_size);
    }

    printf("%d\n", no_of_ways);
    return 0;
}

