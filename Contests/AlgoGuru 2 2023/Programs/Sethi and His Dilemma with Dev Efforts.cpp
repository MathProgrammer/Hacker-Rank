#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    const int MOD = 1e9 + 7;

    int no_of_days, no_of_instructions;
    cin >> no_of_days >> no_of_instructions;

    vector <int> query_left(no_of_instructions + 1), query_right(no_of_instructions + 1);
    vector <int> query_type(no_of_instructions + 1);
    vector <long long> query_value(no_of_instructions + 1);
    for(int i = 1; i <= no_of_instructions; i++)
    {
        int index;
        cin >> index >> query_type[i] >> query_left[i] >> query_right[i];
        query_value[i] = 1;
    }

    vector <long long> queries_starting(no_of_days + 1), queries_ending(no_of_days + 1);
    for(int i = no_of_instructions; i >= 1; i--)
    {
        if(query_type[i] == 1)
        {
            queries_starting[query_left[i]] += query_value[i];
            queries_starting[query_left[i]] %= MOD;

            queries_ending[query_right[i]] += query_value[i];
            queries_ending[query_right[i]] %= MOD;
        }
        else if(query_type[i] == 2)
        {
            for(int j = query_left[i]; j <= query_right[i]; j++)
            {
                query_value[j] += query_value[i];
                query_value[j] %= MOD;
            }
        }
    }

    vector <long long> answer(no_of_days + 1);
    for(int i = 1; i <= no_of_days; i++)
    {
        answer[i] = answer[i - 1] + queries_starting[i] - queries_ending[i - 1];
        answer[i] += MOD;
        answer[i] %= MOD;
    }


    for(int i = 1; i <= no_of_days; i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";
    return 0;
}

