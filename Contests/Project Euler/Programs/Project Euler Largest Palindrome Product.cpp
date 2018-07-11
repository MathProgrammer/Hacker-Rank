#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

int reverse(int n)
{
    int rev = 0;

    while(n)
    {
        rev = rev*10 + n%10;
        n = n/10;
    }

    return rev;
}

int is_palindrome(int n)
{
    return (n == reverse(n));
}

void precompute(vector <int> &palindrome_products)
{
    const int SMALLEST_3_DIGIT = 100, LARGEST_3_DIGIT = 999;

    for(int i = SMALLEST_3_DIGIT; i <= LARGEST_3_DIGIT; i++)
    {
        for(int j = i + 1; j <= LARGEST_3_DIGIT; j++)
        {
            if(is_palindrome(i*j))
                palindrome_products.push_back(i*j);
        }
    }
}

int main()
{
    vector <int> palindrome_products;
    precompute(palindrome_products);

    sort(all(palindrome_products));

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n;
        scanf("%d", &n);

        int answer_location = lower_bound(all(palindrome_products), n) - palindrome_products.begin();
        int answer = palindrome_products[answer_location - 1];

        printf("%d\n", answer);
    }

    return 0;
}
