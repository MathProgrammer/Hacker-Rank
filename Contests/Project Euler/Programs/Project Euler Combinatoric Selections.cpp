#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N;
    long long k;
    scanf("%d %lld", &N, &k);

    long long combinations[N + 1][N + 1] = {{false}};
    int greater_than[N + 1][N + 1] = {{false}};

    for(int n = 0; n <= N; n++)
    {
        for(int r = 0; r <= n; r++)
        {
            if(r == 0 || r == n)
            {
                combinations[n][r] = 1;
            }
            else if(greater_than[n - 1][r] || greater_than[n - 1][r - 1])
            {
                greater_than[n][r] = true;
            }
            else
            {
                if(combinations[n - 1][r] < LONG_MAX - combinations[n - 1][r - 1])
                    combinations[n][r] = combinations[n - 1][r] + combinations[n - 1][r - 1];
                else
                    combinations[n][r] = LONG_MAX;

                greater_than[n][r] = (combinations[n][r] > k);
            }
        }
    }

    int no_of_values_greater_than = 0;
    for(int n = 0; n <= N; n++)
        for(int r = 0; r <= n; r++)
            no_of_values_greater_than += greater_than[n][r];

    printf("%d\n", no_of_values_greater_than);
    return 0;
}
