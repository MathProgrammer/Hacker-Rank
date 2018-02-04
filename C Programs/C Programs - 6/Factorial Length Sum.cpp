#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void precompute(vector <long long> &sum_prime_powers_till, int MAX)
{
    vector <int> largest_prime_factor(MAX + 1, 0);
    vector <int> prime_powers(MAX + 1, 0);
    for(int i = 2; i <= MAX; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple <= MAX; multiple += i)
                largest_prime_factor[multiple] = i;
        }

        int exponent = 0, reduced_i = i;

        while(reduced_i%largest_prime_factor[i] == 0)
        {
            exponent++;
            reduced_i /= largest_prime_factor[i];
        }

        prime_powers[i] = exponent + prime_powers[reduced_i];
    }

    for(int i = 1; i <= MAX; i++)
        sum_prime_powers_till[i] = sum_prime_powers_till[i - 1] + prime_powers[i];
}

int main()
{
    const int MAX = 1e6;

    vector <long long> sum_prime_powers_till(MAX + 1, 0);
    precompute(sum_prime_powers_till, MAX);

    int number_of_elements;
    scanf("%d", &number_of_elements);

    vector <long long> P(number_of_elements, 0);
    for(int i = 0; i < number_of_elements; i++)
    {
        int a_i;
        scanf("%d", &a_i);

        P[i] = sum_prime_powers_till[a_i];
    }

    const int MAX_MASK = 1 << number_of_elements;
    long long total_subsequence_sum  = 0;

    for(int mask = 1; mask < MAX_MASK; mask++)
    {
        long long subsequence_sum = 0;

        for(int i = 0; (1 << i) <= mask; i++)
        {
            if( (mask & (1 << i)) != 0)
                subsequence_sum += P[i];
        }

        total_subsequence_sum += (subsequence_sum%2 == 0 ? subsequence_sum : 0);
    }

    printf("%lld\n", total_subsequence_sum);
    return 0;
}
