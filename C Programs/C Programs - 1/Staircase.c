#include <stdio.h>

int main()
{
    int no_of_floors, i, current_floor;

    scanf("%d", &no_of_floors);

    for(current_floor = 1; current_floor <= no_of_floors; current_floor++) //The top floor is floor no 1 and the bottom most floor is floor no n
    {
        for(i = 1; i <= (no_of_floors - current_floor); i++)
            printf(" ");

        for(i = 1; i <= current_floor; i++)
            printf("#");

        printf("\n");
    }
    return 0;
}
