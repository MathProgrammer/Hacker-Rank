#include <stdio.h>

int main()
{
    int no_of_test_cases, no_of_towers, height_of_tower;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        scanf("%d %d", &no_of_towers, &height_of_tower);

        /*If all the towers are of height 1, Player 1 cannot make a move and loses by force.
        If there are an even number of towers, Player 2 adopts a symmetric strategy.
        If Player 1 reduces a pile from x to y, Player 2 does the same to another tower.
        Player 2 always has a move.
        If there are an odd number of piles, Player 1 reduces 1 pile to height 1 and now enters a game with an even number of piles as the second player.*/
        printf( (height_of_tower == 1 || no_of_towers%2 == 0) ? "2\n" : "1\n");
    }
    return 0;
}
