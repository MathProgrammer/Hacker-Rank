#include <stdio.h>

int main()
{
    int side_1, highest_power_of_2 = 0, greatest_odd_factor;
    long long side_2, side_3, k;
    scanf("%d", &side_1);

    /*Fact 1 = If (a, b, c) is a Pythagorean triple, then (ka, kb, kc) is also a Pythaogorean triple.

	k^2(a^2 + b^2) = (kc)^2

    Fact 2 - Every integer n can be written as n = 2^a . m, where m is an odd integer and a >= 0.

    ------------------------------------------------------------

    Case 1- n is a power of 2, n = 2^a. 1

	(4, 3, 5) = (2^2, 3, 5) is a Pythagorean triple.

	Multiply the entire triple by 2^{a-2}, This makes the first term 2^{a} and since the entire triplet is scaled,
	it retains the Pythagorean property by Fact 1.

    Case 2 - n is an odd number, i.e. n = 2^{0}.m

	Square n,

	(2k + 1) = n^2,
	(2k + 1)^2 + k^2 = (k+1)^2,

	This means (n, k, k+1) form a Pythagorean triple, where k = (n^2 - 1)/2

    Case 3 - n = 2^a . m,

	Then, solve the problem for the odd number m (Case 2) and then scale the triplet by 2^a (Fact 1).*/

    greatest_odd_factor = side_1;
    for(greatest_odd_factor = side_1; greatest_odd_factor%2 != 1; highest_power_of_2++)
    {
        greatest_odd_factor = greatest_odd_factor >> 1;
    }

    if(greatest_odd_factor == 1)// n = 2^a, In this case, simply scale (4, 3, 5) by 2^(a-2), this makes 4 -> 2^a,
    {
        side_2 = (1 << ( highest_power_of_2 - 2) )*3LL;
        side_3 = (1 << ( highest_power_of_2 - 2) )*5LL;
    }
    else
    {
        k = ((greatest_odd_factor*1LL*greatest_odd_factor) - 1)/2;
        side_2 = (1 << highest_power_of_2)*k;
        side_3 = (1 << highest_power_of_2)*(k + 1);
    }

    printf("%d %lld %lld\n",side_1, side_2, side_3);
    return 0;
}
