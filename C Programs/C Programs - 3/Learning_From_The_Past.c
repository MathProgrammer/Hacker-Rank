#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_days, x, y, z, i, minimum, max_profit_day, max_overall_profit = 0;
    scanf("%d", &no_of_days);

    for(i = 1 ; i <= no_of_days; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        minimum = min(x, min(y, z));
        max_profit_day = (x + y + z) - minimum;

        max_overall_profit = max(max_overall_profit, max_profit_day);
    }

    printf("%d\n",max_overall_profit);
    return 0;
}
