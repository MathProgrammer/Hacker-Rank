#include <stdio.h>

#define MAX_BULBS 10000

int main()
{
    int no_of_queries;
    int no_of_combinations[MAX_BULBS + 1], no_of_bulbs;
    const int MOD = 1e5;

    no_of_combinations[1] = 1;
    for(no_of_bulbs = 1; no_of_bulbs <= MAX_BULBS; no_of_bulbs++)
    {
        //Place a new bulb at the beginning. If this bulb is switched on, then the rest has f(n - 1) combinations and if it's off, f(n - 1) combinations
        //Add 1 Because it is possible for the first bulb to be on and all n-1 bulbs to be switched off, which is not counted by f(n-1)
       no_of_combinations[no_of_bulbs] = (no_of_combinations[no_of_bulbs-1]*2)%MOD + 1;
    }

    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
    {
        scanf("%d", &no_of_bulbs);
        printf("%d\n", no_of_combinations[no_of_bulbs]);
    }
    return 0;
}
