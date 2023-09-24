#include <iostream>
#include <map>

using namespace std;


int main()
{
    string S;
    cin >> S;

    int answer = 0;
    map <char, int> max_sequence_ending_at;
    for(int i = 0; i < S.size(); i++)
    {
        char current = S[i];
        char other = (S[i] == 'T' ? 'C' : 'T');

        max_sequence_ending_at[current] = max(max_sequence_ending_at[current], 1 + max_sequence_ending_at[other]);
        answer = max(answer, max_sequence_ending_at[current]);
    }

    cout << answer << "\n";
    return 0;
}
