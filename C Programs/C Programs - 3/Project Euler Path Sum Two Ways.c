#include <stdio.h>

#define NUMBER_OF_ROWS 1000 + 5
#define NUMBER_OF_COLUMNS 1000 + 5
#define min(a, b) (a < b ? a : b)

int matrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
long long min_sum_starting_here[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {{0}};

int main()
{
    int row, column, order_of_matrix, i;
    scanf("%d", &order_of_matrix);

    for(row = 1; row <= order_of_matrix; row++)
        for(column = 1; column <= order_of_matrix; column++)
            scanf("%d", &matrix[row][column]);

    //Initial conditions of the DP. Elements on the last column f(i, n) = m(i, n) + f(i + 1, n) and same for last row, with indices reversed.
    min_sum_starting_here[order_of_matrix][order_of_matrix] = matrix[order_of_matrix][order_of_matrix];
    for(i = order_of_matrix - 1; i >= 1; i--)
    {
        min_sum_starting_here[i][order_of_matrix] = matrix[i][order_of_matrix] +  min_sum_starting_here[i + 1][order_of_matrix];
        min_sum_starting_here[order_of_matrix][i] = matrix[order_of_matrix][i] +  min_sum_starting_here[order_of_matrix][i + 1];
    }

    for(row = order_of_matrix - 1; row >= 1; row--)
        for(column = order_of_matrix - 1; column >= 1; column--)
            min_sum_starting_here[row][column] = matrix[row][column] + min(min_sum_starting_here[row][column + 1], min_sum_starting_here[row + 1][column]);


    printf("%lld\n", min_sum_starting_here[1][1]); //The first element

    return 0;
}

