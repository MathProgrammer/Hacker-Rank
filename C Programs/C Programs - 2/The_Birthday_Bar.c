#include <stdio.h>

int main()
{
    int no_of_squares, day, month, sum = 0, i, chocolate_number[100], no_of_pieces = 0;
    scanf("%d", &no_of_squares);

    for(i = 0; i < no_of_squares; i++)
        scanf("%d", &chocolate_number[i]);

    scanf("%d %d", &day, &month);

    for(i = 0; i < no_of_squares; i++)
    {
        sum += (i < month ? chocolate_number[i] : chocolate_number[i] - chocolate_number[i - month]);

        if(i + 1 >= month && sum == day)
            no_of_pieces++;
    }

    printf("%d\n",no_of_pieces);
    return 0;
}
