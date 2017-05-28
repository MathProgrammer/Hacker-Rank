#include <stdio.h>

#define SIZE 1000
int main()
{
    int no_of_queries;
    int combinations[SIZE][SIZE], n, r;
    const int MOD = 1e9;

    for(n = 0; n < SIZE; n++)
    {
        for(r = 0; r <= n; r++)
        {
            if(n == 0 || r== 0 || r == n)
                combinations[n][r] = 1;
            else if(r == 1 || r == n-1)
                combinations[n][r] = n;
            else
                combinations[n][r] = (combinations[n-1][r-1] + combinations[n-1][r])%MOD;
        }
    }

    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
    {
        scanf("%d", &n);
        for(r = 0; r <= n; r++)
            printf("%d ",combinations[n][r]);
        printf("\n");
    }
    return 0;
}
