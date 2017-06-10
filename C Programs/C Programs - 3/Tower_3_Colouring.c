#include <stdio.h>

long long power(int x, int n, int MOD)
{
    long long result = 1LL;

    while(n > 0)
    {
        if(n%2 == 1)
            result = (result*1LL*x)%MOD;

        x = (x*1LL*x)%MOD;
        n = n/2;
    }
    return (result%MOD);
}

int main()
{
    const int MOD = 1e9 + 7;
    int n;
    long long no_of_colourings, number_of_blocks;

    scanf("%d", &n);

    /*3^m (mod p) = 3^{q.phi(p) + r} (mod p), Writing m as q.phi(p) + r, where q and r are the quotient and remainder on division by phi(p)
                  = {3^phi(p)}^q . 3^r (mod p)
                  = 1^q . 3^r (mod p), Euler's theorem says that a^{phi(n)} = 1 (mod n), if a and n are coprime - 3 and p are coprime in this case,
                                            since they are both prime numbers
                  = 1. 3^r (mod p)
                  = 3^r (mod p), where r is the residue of m with phi(p)
    Since, p is prime, phi(p) = p-1

    First evaluate m = 3^n (mod p-1)
    Then, evaluate ans = 3^m (mod p)     */

    number_of_blocks = power(3, n, MOD-1); //number_of_blocks = 3^n (mod phi(p)), since p is prime, phi(p) = p-1
    no_of_colourings = power(3, number_of_blocks , MOD ); //3^number_of_blocks (mod p) is the answer

    printf("%lld\n",no_of_colourings);
    return 0;
}
