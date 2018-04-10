#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)
using namespace std;

const int MAX_LETTERS = 1e5 + 5;
vector <int> transform[MAX_LETTERS];
vector <int> component(MAX_LETTERS, 0);

void dfs_and_mark(int v, int component_no)
{
    component[v] = component_no;

    for(int i = 0; i < transform[v].size(); i++)
    {
        int child = transform[v][i];

        if(component[child] == 0)
            dfs_and_mark(child, component_no);
    }
}

int find_longest_palindromic_subsequence(vector <int> &input, int length)
{
    typedef vector <int> v_int;
    vector <v_int> longest_palindrome(length + 1, v_int(length + 1, 0));

    for(int i = 1; i <= length; i++)
        longest_palindrome[i][i] = 1;

    for(int current_length = 2; current_length <= length; current_length++)
    {
        for(int start = 1, end = start + current_length - 1; end <= length; start++, end++)
        {
            longest_palindrome[start][end] = max(longest_palindrome[start + 1][end], longest_palindrome[start][end - 1]);

            if(component[input[start]] == component[input[end]])
            {
                longest_palindrome[start][end] = max(longest_palindrome[start][end], 2 + longest_palindrome[start + 1][end - 1]);
            }
        }
    }

    return longest_palindrome[1][length];
}

int main()
{
    int no_of_letters, no_of_transformations, length;
    cin >> no_of_letters >> no_of_transformations >> length;

    for(int i = 1; i <= no_of_transformations; i++)
    {
        int x, y;
        cin >> x >> y;

        transform[x].push_back(y);
        transform[y].push_back(x);
    }

    vector <int> input(length + 1);
    for(int i = 1; i <= length; i++)
        cin >> input[i];

    int component_no = 1;
    for(int i = 1; i <= no_of_letters; i++)
    {
        if(component[i] == 0)
        {
            dfs_and_mark(i, component_no++);
        }
    }

    int longest_palindromic_subsequence = find_longest_palindromic_subsequence(input, length);

    cout << longest_palindromic_subsequence;

    return 0;
}
