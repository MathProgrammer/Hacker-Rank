#include <iostream>
#include <vector>

using namespace std;

void solve() 
{    
    long long k, left, right; 
    cin >> k >> left >> right;
    
    vector <long long> terms; 
    terms.push_back(1); 
    while(terms.back() <= (right - 1)/k)
    {
        long long next = terms.back()*k + 1; 
        terms.push_back(next);
        //cout << "Last term " << terms.back() << "\n";
    }
    
    const int MOD = 1e9 + 7;
    long long answer = 0;
    for(long long term : terms)
    {
        long long contribution = right - max(left - 1, term - 1);
        contribution %= MOD;
        
        answer += (term*contribution)%MOD;
        answer %= MOD;
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_queries; 
    cin >> no_of_queries; 
    
    while(no_of_queries--)
        solve();
    
    return 0;
}
