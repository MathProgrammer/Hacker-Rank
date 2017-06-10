#include <stdio.h>

void solve()
{
    int n, i, number_of_even_factors = 0;
    scanf("%d",&n);

    if(n%2 == 0)
        for(i = 1; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                if(i*i != n && i%2 == 0 && (n/i)%2 == 0)
                    number_of_even_factors +=2;
                else if(i%2 == 0 || (n%i) == 0)
                    number_of_even_factors++;
            }
        }

    printf("%d\n", number_of_even_factors);
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases--)
        solve();

    return 0;
}
