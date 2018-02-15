#include <bits/stdc++.h>

using namespace std;

int main()
{
    int no_of_doors;
    scanf("%d", &no_of_doors);

    vector<int> doors(no_of_doors + 1);
    for(int doors_i = 1; doors_i <= no_of_doors; doors_i++)
       scanf("%d", &doors[doors_i]);

    int minimum_operations = 0;
    for(int i = 1; i <= no_of_doors; i += (doors[i] == 1 ? 2 : 1))
    {
        minimum_operations += (doors[i] == 1);
    }

    int maximum_operations = 0;
    for(int i = no_of_doors; i >= 1; i--)
        maximum_operations += (doors[i] == 1);

    printf("%d %d", minimum_operations, maximum_operations);

    return 0;
}

