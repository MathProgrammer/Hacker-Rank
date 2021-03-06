#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

int get_score(string name)
{
    int total = 0;

    for(int i = 0; i < name.size(); i++)
        total += name[i] - 'A' + 1;

    return total;
}

int main()
{
    int no_of_names;
    scanf("%d", &no_of_names);

    vector <string> name(no_of_names);
    for(int i = 0; i < no_of_names; i++)
        cin >> name[i];

    sort(all(name));

    map <string, int> score;

    for(int i = 0; i < no_of_names; i++)
    {
        score[name[i]] = (i + 1)*get_score(name[i]);
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        string query_name;
        cin >> query_name;
        printf("%d\n", score[query_name]);
    }

    return 0;
}
