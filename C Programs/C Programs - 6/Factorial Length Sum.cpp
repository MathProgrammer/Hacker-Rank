#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void precompute(vector <long long> &sum_factorial_length, int MAX)
{
    vector <int> largest_prime_factor(MAX + 1, 0);
    vector <int> factorial_length(MAX + 1, 0);
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

        factorial_length[i] = exponent + factorial_length[reduced_i];
    }

    for(int i = 1; i <= MAX; i++)
        sum_factorial_length[i] = sum_factorial_length[i - 1] + factorial_length[i];
}

int main()
{
    const int MAX = 1e6;

    vector <long long> sum_factorial_length(MAX + 1, 0);
    precompute(sum_factorial_length, MAX);

    int number_of_elements;
    scanf("%d", &number_of_elements);

    vector <long long> P(number_of_elements, 0);
    for(int i = 0; i < number_of_elements; i++)
    {
        int a_i;
        scanf("%d", &a_i);

        P[i] = sum_factorial_length[a_i];
    }

    const int MAX_MASK = 1 << number_of_elements;
    long long total_pleasing_value  = 0;

    for(int mask = 1; mask < MAX_MASK; mask++)
    {
        long long pleasing_value = 0;

        for(int i = 0; (1 << i) <= mask; i++)
        {
            if( (mask & (1 << i)) != 0)
                pleasing_value += P[i];
        }

        total_pleasing_value += (pleasing_value%2 == 0 ? pleasing_value : 0);
    }

    printf("%lld\n", total_pleasing_value);
    return 0;
}
