#include <bits/stdc++.h>
#define MAX_SIZE 100000 + 1

using namespace std;

int main()
{
    int no_of_elements, array[MAX_SIZE], i, min_difference  = 2e9 + 1;

    cin >> no_of_elements;
    for(i = 0; i < no_of_elements; i++)
        cin >> array[i];

    sort(array, array + no_of_elements);

    for(i = 1; i < no_of_elements; i++)
        min_difference = min(min_difference, array[i] - array[i-1]);

    cout << min_difference;

    return 0;
}

