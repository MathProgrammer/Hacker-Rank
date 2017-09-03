#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element_max(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element_max[i]);

    typedef vector <int> v_int;
    vector <v_int> maximum_till(no_of_elements + 1, v_int(2, 0));
    const int LAST_ELEMENT_MAX = 1, LAST_ELEMENT_ONE = 0;

    for(int i = 2; i <= no_of_elements; i++)
    {
        maximum_till[i][LAST_ELEMENT_MAX] = max(abs(element_max[i] - 1) + maximum_till[i - 1][LAST_ELEMENT_ONE],
                                                abs(element_max[i] - element_max[i - 1]) + maximum_till[i - 1][LAST_ELEMENT_MAX] );

        maximum_till[i][LAST_ELEMENT_ONE] = max(abs(element_max[i - 1] - 1) + maximum_till[i - 1][LAST_ELEMENT_MAX],
                                                (1 - 1) + maximum_till[i - 1][LAST_ELEMENT_ONE]);
    }

    int answer = max(maximum_till[no_of_elements][LAST_ELEMENT_MAX], maximum_till[no_of_elements][LAST_ELEMENT_ONE]);
    printf("%d\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

