#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct info
{
    int base, exponent;
    long double log_form;
};

int sort_by_log(const info &A, const info &B)
{
    return (A.log_form < B.log_form);
}

int main()
{
    int no_of_pairs;
    scanf("%d", &no_of_pairs);

    vector <info> A(no_of_pairs);
    for(int i = 0; i < no_of_pairs; i++)
    {
        scanf("%d %d", &A[i].base, &A[i].exponent);
        A[i].log_form = A[i].exponent*log(A[i].base);
    }

    sort(all(A), sort_by_log);

    int k;
    scanf("%d", &k);

    printf("%d %d\n", A[k - 1].base, A[k - 1].exponent);
    return 0;
}

