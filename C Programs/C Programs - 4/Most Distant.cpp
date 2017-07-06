#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_points;
    scanf("%d", &no_of_points);

    int x, y, max_x = 0, max_y = 0, min_x = 1e9, min_y = 1e9;
    while(no_of_points--)
    {
        scanf("%d %d", &x, &y);

        max_x = max(max_x, x); min_x = min(min_x, x);
        max_y = max(max_y, y); min_y = min(min_y, y);
    }

    double max_distance = max(max_x - min_x, max_y - min_y);
    max_distance = max(max_distance, sqrt(max_x*1LL*max_x + max_y*1LL*max_y));
    max_distance = max(max_distance, sqrt(max_x*1LL*max_x + min_y*1LL*min_y));
    max_distance = max(max_distance, sqrt(min_x*1LL*min_x + max_y*1LL*max_y));
    max_distance = max(max_distance, sqrt(min_x*1LL*min_x + min_y*1LL*min_y));

    printf("%.6f\n", max_distance);
    return 0;
}

