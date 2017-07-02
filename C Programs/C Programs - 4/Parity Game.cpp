#include <cstdio>

int main()
{
    int n, sum, element_i;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &element_i);

        sum += element_i;
    }

    if(sum%2 == 1 && n == 1)
        printf("-1\n");
    else
        printf("%d\n", (sum%2 == 1 && n > 1 ? 1 : 0) );

    return 0;
}

