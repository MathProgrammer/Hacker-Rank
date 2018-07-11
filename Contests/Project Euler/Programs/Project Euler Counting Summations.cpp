#include <cstdio>

const int MAX_N = 1e3 + 1, MOD = 1e9 + 7;
long long no_of_ways[MAX_N][MAX_N] = {{0}};

void precompute()
{
    for(int largest_part = 0; largest_part < MAX_N; largest_part++)
        no_of_ways[0][largest_part] = 1;

    for(int n = 1; n < MAX_N; n++)
    {
        no_of_ways[n][1] = 1;

        for(int largest_part = 2; largest_part < MAX_N; largest_part++)
        {
            no_of_ways[n][largest_part] = no_of_ways[n][largest_part - 1];

            if(largest_part <= n)
                no_of_ways[n][largest_part] += no_of_ways[n - largest_part][largest_part];

            no_of_ways[n][largest_part] %= MOD;
        }
    }
}

int main()
{
    precompute();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int N;
        scanf("%d", &N);
        printf("%lld\n", no_of_ways[N][N - 1]);
    }

    return 0;
}
