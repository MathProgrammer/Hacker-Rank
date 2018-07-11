#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_digits;
    cin >> no_of_digits;
    
    const double PHI = 1.618033987;
    int answer = ceil( (((no_of_digits - 1)*log10(10) + log10(5)/2)/(log10(PHI))) );

    cout << answer << "\n";
}

int main() 
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
