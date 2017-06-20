#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_hurdles, height_i, max_height = 0, initial_high, no_of_magic_drinks;

    cin >> no_of_hurdles >> initial_high;

    for(int i = 0; i < no_of_hurdles; i++)
    {
       cin >> height_i;
       max_height = max(max_height, height_i);
    }

    no_of_magic_drinks = (max_height > initial_high ? max_height - initial_high : 0);
    cout << no_of_magic_drinks;

    return 0;
}
