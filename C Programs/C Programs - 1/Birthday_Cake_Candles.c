#include <stdio.h>

int main()
{
    int i, no_of_candles, current_height, no_of_tallest_candles = 0, tallest_height = 0;

    scanf("%d", &no_of_candles);
    for(i = 1; i <= no_of_candles; i++)
    {
        scanf("%d", &current_height);
        if(tallest_height < current_height)
        {
            tallest_height = current_height;
            no_of_tallest_candles = 0;
        }
        else if(tallest_height == current_height)
        {
            no_of_tallest_candles++;
        }
    }

    printf("%d\n", no_of_tallest_candles);
    return 0;
}
