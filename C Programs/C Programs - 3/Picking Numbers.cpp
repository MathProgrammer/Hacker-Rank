#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_ELEMENT 100 + 1

using namespace std;

int main()
{
    int no_of_elements,element, two_sum, max_two_sum;
    cin >> no_of_elements;

    vector<int> frequency(MAX_ELEMENT, 0);

    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> element;
        frequency[element]++;
    }

    two_sum = max_two_sum = frequency[1] + frequency[2];
    for(int i = 3; i < no_of_elements; i++)
    {
        two_sum += frequency[i] - frequency[i - 2];
        max_two_sum = max(max_two_sum, two_sum);
    }

    cout << max_two_sum << endl;
    return 0;
}

