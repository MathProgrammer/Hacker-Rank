#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <long long> &sum_of_amicable_numbers_till, int LIMIT)
{
    vector <int> sum_of_divisors(LIMIT, 0);

    for(int i = 1; i < LIMIT; i++)
    {
        for(int multiple = 2*i; multiple < LIMIT; multiple += i)
        {
            sum_of_divisors[multiple] += i;
        }
    }

    for(int i = 1; i < LIMIT; i++)
    {
        int divisor_sum = sum_of_divisors[i];

        sum_of_amicable_numbers_till[i] = sum_of_amicable_numbers_till[i - 1] + i*(divisor_sum < LIMIT && divisor_sum != i && sum_of_divisors[divisor_sum] == i);
    }
}

int main()
{
    const int LIMIT = 1e5 + 1;
    vector <long long> sum_of_amicable_numbers_till(LIMIT, 0);
    precompute(sum_of_amicable_numbers_till, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n;
        scanf("%d", &n);

        printf("%lld\n", sum_of_amicable_numbers_till[n]);
    }

    return 0;
}
