#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    set <int> unique_set;
    int previous_element = 0, in_between_1_and_n = true, sorted = true;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        if(element_i < previous_element)
            sorted = false;

        if(element_i < 1 || element_i > no_of_elements)
            in_between_1_and_n = false;

        unique_set.insert(element_i);

        previous_element = element_i;
    }

    printf(unique_set.size() == no_of_elements && in_between_1_and_n && !sorted ? "Beautiful\n" : "Ugly\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
