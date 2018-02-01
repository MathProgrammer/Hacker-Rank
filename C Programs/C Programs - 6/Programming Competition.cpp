#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int no_of_names;
    scanf("%d", &no_of_names);

    string winner;
    int max_score = 0;

    while(no_of_names--)
    {
        string name;
        int dec_problems, jan_problems;
        cin >> name >> dec_problems >> jan_problems;

        int problems_solved = jan_problems - dec_problems;

        if(problems_solved > max_score)
        {
            winner = name;
            max_score = problems_solved;
        }
    }

    cout << winner << " " << max_score;
    return 0;
}
