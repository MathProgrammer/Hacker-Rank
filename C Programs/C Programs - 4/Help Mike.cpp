#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> no_of_elements_i_mod_k(k, 0);

    for(int i = 1; i < k; i++)
        no_of_elements_i_mod_k[i] = n/k + (n%k >= i);

    no_of_elements_i_mod_k[0] = n/k;

    long long no_of_pairs = 0;
    for(int i = 1; i < k; i++)
    {
        int complement = k - i;

        if(complement == i)
            no_of_pairs += no_of_elements_i_mod_k[i]*1LL*(no_of_elements_i_mod_k[i] - 1);
        else
            no_of_pairs += no_of_elements_i_mod_k[i]*1LL*no_of_elements_i_mod_k[k - i];
    }

    no_of_pairs += no_of_elements_i_mod_k[0]*1LL*(no_of_elements_i_mod_k[0] - 1);
    no_of_pairs = no_of_pairs/2;

    printf("%lld\n", no_of_pairs);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

