#include <stdio.h>

int main()
{
    int no_of_test_cases, n;
    long long no_of_multiples;
    scanf("%d",&no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        scanf("%d", &n);

        //We want less than n; not inclusive
        n--;
        no_of_multiples = ( (n/3)*(3 + (n/3)*3L) ) >> 1 ;
        no_of_multiples += ( (n/5)*(5 + (n/5)*5L) ) >> 1;
        no_of_multiples -=  ( (n/15)*(15 + (n/15)*15L) ) >> 1;
        printf("%lld\n",no_of_multiples);
    }
    return 0;
}
