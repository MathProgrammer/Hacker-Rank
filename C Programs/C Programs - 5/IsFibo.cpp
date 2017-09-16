#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void precompute(vector <long long> &fibonacci, int no_of_terms)
{
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for(int i = 2; i <= no_of_terms; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
}

int main()
{
    int no_of_terms = 70;
    vector <long long> fibonacci(no_of_terms + 1);
    precompute(fibonacci, no_of_terms);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        long long n;
        scanf("%lld", &n);

        printf("%s\n", binary_search(all(fibonacci), n) ? "IsFibo" : "IsNotFibo");
    }
    return 0;
}

