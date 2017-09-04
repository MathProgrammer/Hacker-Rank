#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct ComplexNo
{
    long long real, imaginary;
};

ComplexNo product_mod(ComplexNo x, ComplexNo y, int mod)
{
    ComplexNo product;

    long long a = (x.real)%mod, b = (x.imaginary)%mod;
    long long c = (y.real)%mod, d = (y.imaginary)%mod;

    product.real = ((a*c)%mod - (b*d)%mod + mod)%mod;
    product.imaginary = ((a*d)%mod + (b*c)%mod)%mod;

    return product;
}
ComplexNo power_mod(ComplexNo x, long long power, int mod)
{
    ComplexNo y = x, result;
    result.real = 1;
    result.imaginary = 0;

    while(power > 0)
    {
        if(power%2 == 1)
            result = product_mod(result, y, mod);

        y = product_mod(y, y, mod);
        power = power >> 1;
    }

    return result;
}

void solve()
{
    int mod;
    ComplexNo num;
    long long power;

    scanf("%lld %lld %lld %d", &num.real, &num.imaginary, &power, &mod);

    ComplexNo answer = power_mod(num, power, mod);
    printf("%lld %lld\n", answer.real, answer.imaginary);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

