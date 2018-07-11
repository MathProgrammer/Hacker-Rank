#include <cstdio>
#include <vector>
#include <set>

using namespace std;

void precompute(vector <int> &squares)
{
    for(int i = 1; i*i <= 1e9; i++)
        squares.push_back(i*i);
}

int reverse(int n)
{
    int rev = 0;

    while(n)
    {
        rev = rev*10 + n%10;
        n /= 10;
    }

    return rev;
}

int is_palindrome(int n)
{
    return (n == reverse(n));
}

void solve(vector <int> &squares)
{
    int N, difference;
    scanf("%d %d", &N, &difference);

    set <int> palindromes;
    for(int left = 0; left < squares.size(); left++)
    {
        long long square_sum = squares[left];

        for(int right = left + difference; right < squares.size() && square_sum + squares[right] < N; right += difference)
        {
            square_sum += squares[right];

            if(is_palindrome(square_sum))
                palindromes.insert(square_sum);
        }
    }

    long long palindromic_sum = 0;
    for(set <int> :: iterator i = palindromes.begin(); i != palindromes.end(); i++)
        palindromic_sum += *i;

    printf("%lld\n", palindromic_sum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    vector <int> squares;
    precompute(squares);

    while(no_of_test_cases--)
        solve(squares);

    return 0;
}
