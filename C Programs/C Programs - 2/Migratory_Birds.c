#include <stdio.h>
#define NO_OF_BIRDS 5

int main()
{
    int frequency[NO_OF_BIRDS + 1] = {0}, current_type, i, no_of_birds, most_frequent_type = 0;
    scanf("%d",&no_of_birds);

    for(i = 1; i <= no_of_birds; i++)
    {
        scanf("%d", &current_type);
        frequency[current_type]++;
    }

    for(i = 1; i <= NO_OF_BIRDS; i++)
        if(frequency[i] > frequency[most_frequent_type])
            most_frequent_type = i;

    printf("%d\n",most_frequent_type);
    return 0;
}
