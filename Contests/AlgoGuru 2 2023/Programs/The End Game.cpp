#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int mex(set <int> &S)
{
    for(int m = 0; ; m++)
    {
        if(S.count(m) == 0)
        {
            return m;
        }
    }
}

int power_2(int p)
{
    return (1 << p);
}

int get_first_greater_index(int value, int left, int right, vector <int> &A)
{
    if(value <= A[left])
    {
        return left;
    }
    
    while(right - left > 1)
    {
        int mid = (left + right)/2;
        
        if(value <= A[mid])
        {
            right = mid;
        }
        else 
        {
            left = mid;
        }
    }
    
    return right;
}

const int MAX_A = 1e6 + 5, MAX_L = 21;
int grundy[MAX_A][MAX_L];

void solve()
{
    int no_of_elements; 
    cin >> no_of_elements; 
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int oo = 1e9;
    A.push_back(oo);
    
    sort(A.begin(), A.end());
    
    for(int i = no_of_elements + 1; i >= 1; i--)
    {
        for(int moves = MAX_L - 1; moves >= 0; moves--)
        {
            if(i == no_of_elements + 1)
            {
                grundy[i][moves] = 0;
            }
            else if(power_2(moves) > A[i])
            {
                continue;
            }
            else 
            {
                set <int> next_states;
                
                int remove_state = grundy[i + 1][moves];
                next_states.insert(remove_state);
                
                int first_greater_index = get_first_greater_index(power_2(moves + 1), i, no_of_elements + 1, A);
                int divide_state = grundy[first_greater_index][moves + 1];
                next_states.insert(divide_state);
                
                grundy[i][moves] = mex(next_states);
            }
        }
    }
    
    int initial_grundy = grundy[1][0];
    
    cout << (initial_grundy != 0 ? "Gamze" : "Yasin") << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases; 
    cin >> no_of_test_cases; 
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
