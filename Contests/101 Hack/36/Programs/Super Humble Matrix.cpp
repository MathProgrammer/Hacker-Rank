#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int rows, columns; 
    cin >> rows >> columns;
    
    const int MOD = 1e9 + 7, MAX_SUM = rows + columns;
    vector <long long> factorial(MAX_SUM + 1); 
    factorial[0] = 1;
    for(int i = 1; i <= MAX_SUM; i++)
    {
        factorial[i] = (i*factorial[i - 1])%MOD;
    }
    
    long long no_of_ways = 1;
    for(int sum = 2; sum <= MAX_SUM; sum++)
    {
        int smallest_row = max(sum - columns, 1), largest_row = min(sum - 1, rows);
        int diagonal_size = largest_row - smallest_row + 1;
        long long no_of_ways_to_permute_diagonal = factorial[diagonal_size];
        
        no_of_ways *= no_of_ways_to_permute_diagonal;
        no_of_ways %= MOD;
    }

    cout << no_of_ways << "\n";
    return 0;
}