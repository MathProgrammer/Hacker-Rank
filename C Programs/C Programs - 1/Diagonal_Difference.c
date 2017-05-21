#include <stdio.h>

#define absolute(a) a > 0 ? a : (0 - a)
int main()
{
    int diagonal_sum = 0, anti_diagonal_sum = 0, order_of_matrix, i, j, current_element, difference;
    scanf("%d", &order_of_matrix);

    for(i = 1; i <= order_of_matrix; i++)
    {
        for(j = 1; j <= order_of_matrix; j++)
        {
            scanf("%d",&current_element);

            if(i == j)
                diagonal_sum += current_element;
            if(i + j == order_of_matrix + 1)
                anti_diagonal_sum += current_element;
        }
    }
    difference = diagonal_sum - anti_diagonal_sum;
    printf("%d", absolute(difference));
    return 0;
}
