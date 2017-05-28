#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(unsigned long a, unsigned long b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;

    if(a%2 == 0)
        if(b%2 == 0)
            return 2*gcd(a >> 1, b >> 1);
        else
            return gcd(a >> 1, b);
    else
        if(b%2 == 0)
            return gcd(a, b >> 1);
        else
            return gcd(min(a, b), (max(a, b) - min(a, b) ) >> 1);
}
int main()
{
    int no_of_queries;
    unsigned long current_x, current_y, destination_x, destination_y;
    scanf("%d", &no_of_queries);

    while(no_of_queries-- != 0)
    {
        scanf("%ld %ld %ld %ld", &current_x, &current_y, &destination_x, &destination_y);
        printf(gcd(current_x, current_y) == gcd(destination_x, destination_y) ? "YES\n" : "NO\n");
    }
    return 0;
}
