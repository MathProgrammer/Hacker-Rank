#include <stdio.h>

long long power_mod(long long x, int power, int mod)
{
    long long result = 1;

    while(power > 0)
    {
        if(power%2 == 1)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

    return result;
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int even_nos = 0, odd_nos = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        scanf("%d", &element);

        even_nos += (element%2 == 0);
        odd_nos += (element%2 == 1);
    }

    const int MOD = 1e9 + 7;

    long long only_even_subsets = (power_mod(2, even_nos, MOD) + MOD - 1)%MOD;
    long long only_odd_subsets = (power_mod(2, odd_nos - 1, MOD) + MOD - 1)%MOD;

    long long answer = (only_even_subsets + only_odd_subsets + only_odd_subsets*only_even_subsets)%MOD;

    printf("%lld\n", answer);
    return 0;
}
