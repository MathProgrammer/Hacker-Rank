#include <cstdio>
#include <vector>

using namespace std;

vector <long long> min_number_with_unique_factors;

void precompute_primes()
{
    vector <int> is_prime(100 + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector <int> prime;
    for(int i = 2; i < 100; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple < 100; multiple+= i)
            {
                is_prime[multiple] = false;
            }
            prime.push_back(i);
        }
    }

    min_number_with_unique_factors.push_back(prime[0]);
    for(int i = 1; min_number_with_unique_factors[i - 1] <= 1e18/prime[i]; i++)
    {
        long long new_number = min_number_with_unique_factors.back()*prime[i];

        min_number_with_unique_factors.push_back(new_number);
    }
}

void solve()
{
    long long n;
    unsigned int i = 0;
    scanf("%lld", &n);

    while(min_number_with_unique_factors[i] <= n && i != min_number_with_unique_factors.size())
        i++;

    printf("%u\n", i);
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
