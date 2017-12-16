#include <cstdio>
#include <vector>

using namespace std;

const int N = 4, MOD = 1e9 + 7;

void make_identity(long long I[][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            I[i][j] = (i == j ? 1 : 0);
}

void copy(long long A[][N], long long B[][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            B[i][j] = A[i][j];
}

void multiply(long long A[][N], long long B[][N])
{
    long long P[N][N];

    for(int row = 0; row < N; row++)
    {
        for(int column = 0; column < N; column++)
        {
            P[row][column] = 0;

            for(int i = 0; i < N; i++)
                P[row][column] += (A[row][i]*B[i][column])%MOD;

            P[row][column] %= MOD;
        }
    }

    copy(P, A);
}

void power(long long X[][N], long long power)
{
    long long result[N][N], Y[N][N];

    make_identity(result);
    copy(X, Y);

    while(power)
    {
        if(power%2 == 1)
            multiply(result, Y);

        multiply(Y, Y);
        power = power >> 1;
    }

    copy(result, X);
}

void solve()
{
    long long no_of_tiles;
    scanf("%lld", &no_of_tiles);

    long long tiles[4 + 1];
    tiles[0] = tiles[1] = 1;
    tiles[2] = tiles[1] + tiles[0];
    tiles[3] = tiles[2] + tiles[1] + tiles[0];
    tiles[4] = tiles[3] + tiles[2] + tiles[1] + tiles[0];

    if(no_of_tiles <= 4)
    {
        printf("%lld\n", tiles[no_of_tiles]);
        return;
    }

    long long ans[1][4] = {tiles[4], tiles[3], tiles[2], tiles[1]};

    long long matrix[4][4] = { {1, 1, 0, 0},
                               {1, 0, 1, 0},
                               {1, 0, 0, 1},
                               {1, 0, 0, 0}};

    power(matrix, no_of_tiles - 4);

    multiply(ans, matrix);

    printf("%lld\n", ans[0][0]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
