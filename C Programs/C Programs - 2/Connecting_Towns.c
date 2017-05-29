#include <stdio.h>

int main()
{
    int no_of_test_cases, no_of_towns, no_of_paths, i, no_of_journeys;
    const int MOD = 1234567;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        scanf("%d", &no_of_towns);

        no_of_journeys = 1;
        for(i = 1; i <= no_of_towns - 1; i++)
        {
            scanf("%d", &no_of_paths);
            no_of_journeys = (no_of_journeys*no_of_paths)% MOD;
        }

        printf("%d\n",no_of_journeys);
    }
    return 0;
}
