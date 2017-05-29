#include <stdio.h>
#include <stdlib.h>

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

void read(long long *, int);
long long find_largest_rectangle(long long *, int);

long long find_largest_rectangle(long long *building_height, int no_of_buildings)
{
    int i;
    long long width_of_rectangle = 1, height_of_rectangle = *(building_height + 0);
    long long width_of_rectangle_ending_here, height_of_rectangle_ending_here, answer;
    long long *largest_rectangle_till = malloc(no_of_buildings*sizeof(long long));

    *(largest_rectangle_till + 0) = width_of_rectangle*height_of_rectangle;

    for(i = 1; i < no_of_buildings; i++)
    {
        width_of_rectangle_ending_here = width_of_rectangle + 1;
        height_of_rectangle_ending_here = min(height_of_rectangle, *(building_height + i) );

        *(largest_rectangle_till + i) = max( *(largest_rectangle_till + i - 1), width_of_rectangle_ending_here*height_of_rectangle_ending_here);
        *(largest_rectangle_till + i ) = max(*(largest_rectangle_till + i), *(building_height + i));

        if(*(largest_rectangle_till + i) > width_of_rectangle_ending_here*height_of_rectangle_ending_here)
        width_of_rectangle =  *(largest_rectangle_till + i) > *(largest_rectangle_till + i - 1) ? width_of_rectangle_ending_here : 1;
        height_of_rectangle =  *(largest_rectangle_till + i) > *(largest_rectangle_till + i - 1) ? height_of_rectangle_ending_here : *(building_height + i);
    }
    answer = *(largest_rectangle_till + no_of_buildings - 1);
    free(largest_rectangle_till);

    return answer;
}

int main()
{
    int no_of_buildings;
    long long largest_rectangle;

    scanf("%d",&no_of_buildings);

    long long *building_height = malloc(no_of_buildings*sizeof(long long));

    read(building_height, no_of_buildings);
    largest_rectangle = find_largest_rectangle(building_height, no_of_buildings);

    printf("%I64d\n", largest_rectangle);
    free(building_height);
    return 0;
}

void read(long long *building_height, int no_of_buildings)
{
    int i;

    for(i = 0; i < no_of_buildings; i++)
    {
        scanf("%I64d",(building_height + i));
    }
}
