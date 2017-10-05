#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_piles;
    scanf("%d", &no_of_piles);

    int nim_sum = 0;
    for(int i = 1; i <= no_of_piles; i++)
    {
        int pile_i;
        scanf("%d", &pile_i);

        int mex_i = pile_i + (pile_i%2 == 0 ? - 1 : 1);
        nim_sum ^= mex_i;
    }

    printf("%c\n", nim_sum == 0 ? 'L' : 'W');
}

int main()
{
    int no_of_games;
    scanf("%d", &no_of_games);

    while(no_of_games--)
        solve();

    return 0;
}
