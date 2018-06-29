#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string text;
    int k;
    cin >> text >> k;

    const int no_of_alphabets = 26;
    vector <int> frequency(no_of_alphabets, 0);
    for(unsigned int i = 0; i < text.size(); i++)
        frequency[text[i] - 'a']++;

    string answer;
    for(int i = 0; text[i] != '\0'; i++)
        if(frequency[text[i] - 'a'] >= k)
            answer += text[i];

    cout << answer;
    return 0;
}
