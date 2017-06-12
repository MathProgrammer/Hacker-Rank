#include <stdio.h>

#define INFINITY 1e6 + 1
#define min(a, b) (a < b ? a : b)

int main()
{
    int number_of_elements, i, a_i, b_i, smallest_first_array = INFINITY, second_smallest_first_array, smallest_index_first_array;
    int smallest_second_array = INFINITY, second_smallest_second_array, smallest_index_second_array;
    int sum;
    scanf("%d", &number_of_elements);

    //First Array
    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &a_i);

        if(a_i <= smallest_first_array)
        {
            second_smallest_first_array = smallest_first_array;
            smallest_first_array = a_i;
            smallest_index_first_array = i;
        }
        else if(a_i < second_smallest_first_array)
        {
            second_smallest_first_array = a_i;
        }
    }

    //Second array
    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &b_i);

        if(b_i <= smallest_second_array)
        {
            second_smallest_second_array = smallest_second_array;
            smallest_second_array = b_i;
            smallest_index_second_array = i;
        }
        else if(b_i < second_smallest_second_array)
        {
            second_smallest_second_array = b_i;
        }
    }

    if(smallest_index_first_array != smallest_index_second_array)
        sum = smallest_first_array + smallest_second_array;
    else
        sum = min( (smallest_first_array + second_smallest_second_array), (smallest_second_array + second_smallest_first_array));

    printf("%lld\n", sum);

    return 0;
}
