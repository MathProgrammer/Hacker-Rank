#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define INFINITY 1000001

int main()
{
    int no_of_steps, a, b, final_intersection_a = INFINITY, final_intersection_b = INFINITY;
    long final_area;;
    scanf("%d", &no_of_steps);

    while(no_of_steps-- != 0)
    {
        scanf("%d %d", &a, &b);
        final_intersection_a = min(final_intersection_a, a);
        final_intersection_b = min(final_intersection_b, b);
    }
    final_area = final_intersection_a*1L*final_intersection_b;

    printf("%ld\n",final_area);
    return 0;
}
