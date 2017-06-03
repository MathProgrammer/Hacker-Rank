#include <iostream>
#include <algorithm>
#define MAX_TOYS 100000
using namespace std;

int toy[MAX_TOYS + 1];

int main()
{
   int no_of_toys, i, toys_bought, total_price = 0, budget;

    cin >> no_of_toys >> budget;
    for(int i = 0; i < no_of_toys; i++)
        cin >> toy[i];

    sort(toy, toy + no_of_toys);

    for(toys_bought = 0; (total_price + toy[toys_bought] <= budget) && (toys_bought < no_of_toys); toys_bought++)
    {
        total_price += toy[toys_bought];
    }

   cout << toys_bought;
   return 0;
}
