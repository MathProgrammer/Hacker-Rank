#include <stdio.h>

int main()
{
    int x, y, no_of_test_cases;

    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
    {
        scanf("%d %d", &x, &y);

        x = x % 4;
        y = y % 4;
        printf((x == 3 || x == 0 || y == 3 || y== 0) ? "First\n" : "Second\n");
    }
    return 0;
}
