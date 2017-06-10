#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), (max(a, b)%min(a,b) ) );
}

void solve()
{
    int array_gcd,i, number_i, number_of_elements;
    scanf("%d", &number_of_elements);

    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number_i);
        array_gcd = (i == 1 ? number_i : gcd(array_gcd, number_i));
    }
    printf(array_gcd == 1 ? "YES\n" : "NO\n");
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();
    return 0;
}
