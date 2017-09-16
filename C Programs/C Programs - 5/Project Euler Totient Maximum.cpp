#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define all(v) (v).begin(), (v).end()

int main()
{
    const int LIMIT = 100;
    vector <int> is_prime(LIMIT, true);
    vector <int> primes;

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;
            if(i%primes[j] == 0) break;
        }
    }

    vector <long long> prime_product;
    prime_product.push_back(2);

    for(int i = 1; prime_product.back() < 1e18/primes[i]; i++)
    {
        prime_product.push_back(prime_product.back()*primes[i]);
    }

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        long long n;
        scanf("%lld", &n);

        int answer_index = lower_bound(all(prime_product), n) - prime_product.begin() - 1;

        printf("%lld\n", prime_product[answer_index]);
    }
    return 0;
}
