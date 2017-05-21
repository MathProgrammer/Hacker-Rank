#include <stdio.h>

#define INFINITY 1000000000 + 1
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

int main()
{
    long long minimum = INFINITY, maximum = 0, sum = 0, current_number;
    int i;

    for(i = 1; i <= 5; i++)
    {
        scanf("%I64d", &current_number);
        minimum = min(current_number, minimum);
        maximum = max(current_number, maximum);
        sum = sum + current_number;
    }

    printf("%I64d %I64d", (sum - maximum), (sum - minimum)); //Maximum sum is all numbers except the minimum, and minimum sum is all except the maximum
    return 0;
}
