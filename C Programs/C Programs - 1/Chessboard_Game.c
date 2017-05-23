#include <stdio.h>

int winner[15][15] = {{0}};

int find_winner(int x, int y)
{
    if(x < 1 || x > 15 || y < 1 || y > 15) //Mark illegal positions as winning for Player 1 for convenience.
        return 1;

    if(winner[x][y] == 0)
    {
        /*If the coin is moved from (x, y) to (x1, y1), then the first player is second player from (x1, y1).
            From the current position, check if it is possible to move to a square winning for second player.
            If no move is possible, a loss in unavoidable. All illegal squares are winning for first player by extension ... */

        if(find_winner(x-2, y+1) == 2 || find_winner(x-2, y-1) == 2 || find_winner(x+1, y-2) == 2 || find_winner(x-1, y-2) == 2)
            winner[x][y] = 1;
        else
            winner[x][y] = 2;
    }

    return winner[x][y];
}

int main()
{
    int x, y, no_of_test_cases;

    for(x = 1; x <= 15; x++)
    {
        for(y = 1; y <= 15; y++)
        {
            winner[x][y] = find_winner(x, y);
        }
    }

    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
    {
        scanf("%d %d", &x, &y);
        printf(winner[x][y] == 1 ? "First\n" : "Second\n");
    }
    return 0;
}
