#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int no_of_volcanoes;
    scanf("%d", &no_of_volcanoes);

    vector <int> volcano_x(no_of_volcanoes + 1);
    vector <int> volcano_y(no_of_volcanoes + 1);
    vector <int> power(no_of_volcanoes + 1);

    for(int i = 1; i <= no_of_volcanoes; i++)
        scanf("%d %d %d", &volcano_x[i], &volcano_y[i], &power[i]);

    int maximum_affected_area = 0;
    for(int x = 0; x <= n - 1; x++)
    {
        for(int y = 0; y <= n - 1; y++)
        {
            int current_affected_area = 0;

            for(int i = 1; i <= no_of_volcanoes; i++)
            {
                int distance = max( abs(x - volcano_x[i]), abs(y - volcano_y[i]) );
                int damage = max(0, power[i] - distance);

                current_affected_area += damage;
            }

            maximum_affected_area = max(maximum_affected_area, current_affected_area);
        }
    }

    printf("%d\n", maximum_affected_area);
    return 0;
}

