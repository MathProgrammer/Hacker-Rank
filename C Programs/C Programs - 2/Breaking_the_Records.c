#include <stdio.h>

#define INFINITY 100000001

int main()
{
    int no_of_games, current_score, minimum = INFINITY, maximum = -1, minimum_changes = -1, maximum_changes = -1, i;
    scanf("%d",&no_of_games);
    for(i = 1; i <= no_of_games; i++)
    {
        scanf("%d", &current_score);

        if(current_score > maximum)
        {
            maximum = current_score; maximum_changes++;
        }
        if(current_score < minimum)
        {
            minimum = current_score; minimum_changes++;
        }
    }

    printf("%d %d\n",maximum_changes, minimum_changes);
    return 0;
}
