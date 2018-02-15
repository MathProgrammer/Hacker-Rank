#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void precompute(vector <int> &anti_prime, int LIMIT)
{
    vector <int> largest_prime_factor(LIMIT + 1, 0);
    vector <int> no_of_divisors(LIMIT + 1, 0);
    no_of_divisors[1] = 1;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple <= LIMIT; multiple += i)
            {
                largest_prime_factor[multiple] = i;
            }
        }

        int exponent = 0, reduced_i = i;

        while(reduced_i%largest_prime_factor[i] == 0)
        {
            exponent++;
            reduced_i /= largest_prime_factor[i];
        }

        no_of_divisors[i] = (exponent + 1)*no_of_divisors[reduced_i];
    }

    anti_prime.push_back(1);
    for(int i = 2; i <= LIMIT; i++)
    {
        if(no_of_divisors[i] > no_of_divisors[anti_prime.back()])
        {
            anti_prime.push_back(i);
        }
    }
}

int main()
{
    const int LIMIT = 1e7 + 5e6;
    vector <int> anti_primes;
    precompute(anti_primes, LIMIT);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int n;
        scanf("%d", &n);

        int position = lower_bound(all(anti_primes), n) - anti_primes.begin();
        printf("%d\n", anti_primes[position]);
    }

    return 0;
}
