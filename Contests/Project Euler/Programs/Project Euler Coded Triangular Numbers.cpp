#include <cstdio>

void solve()
{
    long long triangular_n;
    scanf("%lld", &triangular_n);

    int low = 1, high = 1e9;
    int index = -1;

    while(low <= high)
    {
        int mid = (low + high) >> 1;

        long long n = mid;
        long long t_n = (n*(n + 1))/2;

        if(t_n == triangular_n)
        {
            index = mid; break;
        }
        else if(t_n < triangular_n)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("%d\n", index);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
