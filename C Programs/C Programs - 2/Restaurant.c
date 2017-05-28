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
    int square_side, length, breadth, no_of_squares, no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries-- != 0)
    {
        scanf("%d %d",&length, &breadth); //The square side must divide both l and b and is it's gcd
        square_side = gcd(length, breadth);
        no_of_squares = length*breadth/(square_side*square_side);

        printf("%d\n", no_of_squares);
    }

    return 0;
}
