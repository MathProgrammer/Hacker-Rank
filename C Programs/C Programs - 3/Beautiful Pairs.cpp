#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000 + 1
using namespace std;


int main()
{
    int no_of_elements, i, frequency_a[MAX_SIZE] = {0}, frequency_b[MAX_SIZE] = {0}, element, beautiful_pairs = 0;

    cin >> no_of_elements;
    for(i = 0; i < no_of_elements; i++) cin >> element, frequency_a[element]++;
    for(i = 0; i < no_of_elements; i++) cin >> element, frequency_b[element]++;

    for(i = 0; i < MAX_SIZE; i++)
    {
        beautiful_pairs += min(frequency_a[i], frequency_b[i]);
    }

    //If all the elements are matched, making 1 change reduces the number of pairs, and increases it in all other cases
    beautiful_pairs += (beautiful_pairs == no_of_elements ? -1 : 1);

    cout << beautiful_pairs;
    return 0;
}

