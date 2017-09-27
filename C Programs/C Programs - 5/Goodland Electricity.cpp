#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_cities, range;
    scanf("%d %d", &no_of_cities, &range);

    vector <int> has_tower(no_of_cities);
    for(int i = 0; i < no_of_cities; i++)
        scanf("%d", &has_tower[i]);

    int is_possible = true;
    int no_of_towers = 0, left_limit = 0, right_limit, city_i = 0;

    while(city_i < no_of_cities)
    {
        right_limit = min(city_i + range - 1, no_of_cities - 1);

        int tower_target = right_limit;

        while(tower_target >= left_limit && !has_tower[tower_target])
            tower_target--;

        if(tower_target < left_limit)
        {
            is_possible = false;
            break;
        }

       no_of_towers++;
       left_limit = tower_target + 1;

       city_i = tower_target + range;

    }

    printf("%d\n", is_possible ? no_of_towers : -1);
    return 0;
}

