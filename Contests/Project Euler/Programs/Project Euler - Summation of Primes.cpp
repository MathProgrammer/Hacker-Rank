#include <cstdio>
#include <vector>

using namespace std;

vector <long long> prime_sum_till(1e6, 0);

void precompute_primes()
{
    vector <int> is_prime(1e6 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1e6; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 1e6; multiple +=i)
            {
                is_prime[multiple] = false;
            }
        }
    }

    for(int i = 2; i <= 1e6; i++)
    {
        prime_sum_till[i] = prime_sum_till[i - 1] + (is_prime[i] ? i : 0);
    }
}

void solve()
{
    int n;
    scanf("%d", &n);
    printf("%lld\n", prime_sum_till[n]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_primes();

    while(no_of_test_cases--)
        solve();

    return 0;
}


