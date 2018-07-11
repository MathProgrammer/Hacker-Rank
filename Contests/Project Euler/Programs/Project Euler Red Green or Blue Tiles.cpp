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

    long long red[4 + 1] = {1, 1, 1 + 1, 2 + 1, 3 + 2};
    long long red_ans[4][N] = {red[4], red[3], red[2], red[1]};
    long long red_matrix[N][N] = { {1, 1, 0, 0},
                                   {1, 0, 1, 0},
                                   {0, 0, 0, 1},
                                   {0, 0, 0, 0}};


    long long green[4 + 1] = {1, 1, 1, 1 + 1, 2 + 1};
    long long green_ans[4][N] = {green[4], green[3], green[2], green[1]};
    long long green_matrix[N][N] = { {1, 1, 0, 0},
                                     {0, 0, 1, 0},
                                     {1, 0, 0, 1},
                                     {0, 0, 0, 0}};

    long long blue[4 + 1] = {1, 1, 1, 1, 1 + 1};
    long long blue_ans[4][N] = {blue[4], blue[3], blue[2], blue[1]};
    long long blue_matrix[N][N] =   {{1, 1, 0, 0},
                                     {0, 0, 1, 0},
                                     {0, 0, 0, 1},
                                     {1, 0, 0, 0}};

    long long total_red, total_green, total_blue;

    if(no_of_tiles <= 4)
    {
        total_red = red[no_of_tiles] - 1;
        total_green = green[no_of_tiles] - 1;
        total_blue = blue[no_of_tiles] - 1;
    }
    else
    {
        power(red_matrix, no_of_tiles - 4);
        multiply(red_ans, red_matrix);
        total_red = red_ans[0][0] + MOD - 1;

        power(green_matrix, no_of_tiles - 4);
        multiply(green_ans, green_matrix);
        total_green = green_ans[0][0] + MOD - 1;

        power(blue_matrix, no_of_tiles - 4);
        multiply(blue_ans, blue_matrix);
        total_blue = blue_ans[0][0] + MOD - 1;
    }

    long long total = (total_red + total_green + total_blue)%MOD;
    printf("%lld\n", total);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

