#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_buildings;
    scanf("%d", &no_of_buildings);

    vector <int> height(no_of_buildings + 1, 0);
    for(int i = 1; i <= no_of_buildings; i++)
        scanf("%d", &height[i]);

    int energy = 0;
    for(int i = no_of_buildings; i >= 1; i--)
        energy = (energy + height[i])/2 + (energy + height[i])%2;

    printf("%d\n", energy);
    return 0;
}
