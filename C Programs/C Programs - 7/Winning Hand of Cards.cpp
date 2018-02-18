#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_cards, mod, target;
    cin >> no_of_cards >> mod >> target;

    vector<long long> A(no_of_cards + 1);
    for(int i = 1; i <= no_of_cards; i++)  cin >> A[i];

    typedef vector <int> v_int;
    vector <v_int> no_of_combinations(no_of_cards + 1, v_int(mod + 1, 0));

    for(int i = 1; i <= no_of_cards; i++)
    {
        no_of_combinations[i][A[i]%mod]++;

        for(int m = 0; m < mod; m++)
        {
            no_of_combinations[i][m] += no_of_combinations[i - 1][m];

            int product_m = (m*A[i])%mod;

            no_of_combinations[i][product_m] += no_of_combinations[i - 1][m];
        }
    }

    cout << no_of_combinations[no_of_cards][target];
    return 0;
}

