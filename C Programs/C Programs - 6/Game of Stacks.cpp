#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int A_size, B_size, max_sum;
    scanf("%d %d %d", &A_size, &B_size, &max_sum);

    vector <int> A(A_size + 1);
    for(int i = 1; i <= A_size; i++)
        scanf("%d", &A[i]);

    vector <long long> A_sum(A_size + 1, 0);
    for(int i = 1; i <= A_size; i++)
        A_sum[i] = A_sum[i - 1] + A[i];

    vector <int> B(B_size + 1);
    for(int i = 1; i <= B_size; i++)
        scanf("%d", &B[i]);

    vector <long long> B_sum(B_size + 1, 0);
    for(int i = 1; i <= B_size; i++)
        B_sum[i] = B_sum[i - 1] + B[i];

    int max_chosen_elements = 0;

    for(int i = 0; i <= A_size && A_sum[i] <= max_sum; i++)
    {
        int A_elements = i, B_elements;

        int start = 0, end = B_size;

        while(start <= end)
        {
            int mid = (start + end) >> 1;

            if(A_sum[i] + B_sum[mid] <= max_sum)
            {
                if(mid + 1 == B_size + 1 || A_sum[i] + B_sum[mid + 1] > max_sum)
                {
                    B_elements = mid;
                    break;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                end = mid;
            }
        }

        max_chosen_elements = max(max_chosen_elements, A_elements + B_elements);
    }

    printf("%d\n", max_chosen_elements);
}

int main()
{
    int no_of_games;
    scanf("%d", &no_of_games);

    while(no_of_games--)
        solve();

    return 0;
}
