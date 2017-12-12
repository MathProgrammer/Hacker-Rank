#include <cstdio>
#include <vector>

using namespace std;

int reverse(int n, int base)
{
    int rev = 0;

    while(n)
    {
        rev = rev*base + n%base;
        n /= base;
    }

    return rev;
}

int is_palindrome(int n, int base)
{
    return (n == reverse(n, base));
}

int main()
{
    int N, base;
    scanf("%d %d", &N, &base);

    int double_palindrome_sum = 0;
    for(int i = 1; i < N; i++)
    {
        double_palindrome_sum += i*(is_palindrome(i, 10) && is_palindrome(i, base));
    }

    printf("%d\n", double_palindrome_sum);
    return 0;
}
