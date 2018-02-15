#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_people, no_of_flowers;
    cin >> no_of_flowers >> no_of_people;

    vector<int> cost(no_of_flowers);
    for(int i = 0; i < no_of_flowers; i++) cin >> cost[i];

    sort(all(cost));
    reverse(all(cost));

    int minimum_cost = 0, flower_no = 0;

    for(int i = 0; i < no_of_flowers; i++)
    {
        flower_no += (i%no_of_people == 0);

        minimum_cost += flower_no*cost[i];
    }

    cout << minimum_cost;
    return 0;
}
