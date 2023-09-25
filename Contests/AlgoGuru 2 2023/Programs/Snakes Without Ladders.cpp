#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long ceil(long long numerator, long long denominator)
{
    return numerator/denominator + (numerator%denominator != 0);
}

void solve()
{
    int moves;
    long long snakes;
    cin >> snakes >> moves; 
    
    if(moves == 1)
    {
        cout << (snakes == 0 ? 1 : -1) << "\n";
        return ;
    }
    
    const int STARTING = 1;
    long long empty_squares_needed = STARTING + ceil(snakes, moves - 1);
    long long squares = snakes + empty_squares_needed; 
    long long rows = sqrt(2*squares);
    while(rows*(rows + 1) < 2*squares)
    {
        rows++;
    }
 
    cout << rows << "\n";
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
