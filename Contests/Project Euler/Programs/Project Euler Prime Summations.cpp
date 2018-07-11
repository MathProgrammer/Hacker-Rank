#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 1;
long long no_of_ways[MAX_N] = {0};

vector <int> is_prime(MAX_N + 1, true);
vector <int> primes;

void sieve()
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < MAX_N; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < MAX_N; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

void precompute()
{
    sieve();

    no_of_ways[0] = 1;

    for(int i = 1; i < MAX_N; i++)
        no_of_ways[i] = (i%2 == 0);

    for(int j = 1; j < primes.size(); j++)
    {
        for(int i = 1; i < MAX_N; i++)
        {
            if(primes[j] <= i) no_of_ways[i] += no_of_ways[i - primes[j]];
        }
    }

}

int main()
{
    precompute();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int N;
        scanf("%d", &N);
        printf("%lld\n", no_of_ways[N]);
    }

    return 0;
}

