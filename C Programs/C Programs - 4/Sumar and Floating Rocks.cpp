#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    /*Let a/b = (y2 - y1)/(x2 - x1) be the slope in the reduced form.
    WE know slope = tan theta.
    So, to encounter another lattice point we must move a units in the y-direction and b units in the x-direction ...

    (x1 + b, y1 + a) is guaranteed to give us another lattice point because integers are being added and the slope is still the same.

    Number of lattice points = (y2 - y1)/a - 1 = (x2 - x1)/b - 1 ... Subtract 1 to exclude the destination.

    A further simplifaction can be made ... a = (y2 - y1)/gcd  and b = (x2 - x1)/gcd.
    Answer = gcd(y2 - y1, x2 - x1) - 1*/

    while(no_of_test_cases--)
    {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        printf("%d\n", gcd( abs(x2 - x1), abs(y2 - y1) ) - 1);
    }
    return 0;
}

