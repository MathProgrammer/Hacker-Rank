#include <stdio.h>

#define abs(x) (x > 0 ? x : 0 - (x) )
int main()
{
    int cat_a, cat_b, mouse, no_of_queries;
    scanf("%d",&no_of_queries);

    while(no_of_queries-- != 0)
    {
        scanf("%d %d %d",&cat_a, &cat_b, &mouse);

        if(abs(cat_a - mouse) < abs(cat_b - mouse))
            printf("Cat A\n");
        else if(abs(cat_a - mouse) > abs(cat_b - mouse))
            printf("Cat B\n");
        else
            printf("Mouse C\n");
    }
    return 0;
}
