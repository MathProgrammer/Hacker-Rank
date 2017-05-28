#include <stdio.h>

int main()
{
    int no_of_draws, no_of_socks, no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries-- != 0)
    {
        scanf("%d", &no_of_socks);
        no_of_draws = no_of_socks + 1;
        printf("%d\n",no_of_draws);
    }
    return 0;
}
