#include <iostream>

#define MAX_SIZE 100 + 1

using namespace std;

int main()
{
    int no_of_questions, no_of_correct_answers = 0;
    char vincent_answers[MAX_SIZE], catherine_answers[MAX_SIZE];
    cin >> no_of_questions >> vincent_answers >> catherine_answers;

    for(int i = 0; i < no_of_questions; i++)
    {
        if(vincent_answers[i] != '.' && vincent_answers[i] != catherine_answers[i])
            no_of_correct_answers++;
    }

    cout << no_of_correct_answers;
    return 0;
}
