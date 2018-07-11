#include <stdio.h>

#define NUMBER_OF_ROWS 1000 + 1
#define NUMBER_OF_COLUMNS 1000 + 1
#define min(a, b) (a < b ? a : b)

int matrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
long long min_sum_ending_here[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {{0}};

int main()
{
    int row, column, order_of_matrix;
    scanf("%d", &order_of_matrix);

    for(row = 1; row <= order_of_matrix; row++)
    {
        for(column = 1; column <= order_of_matrix; column++)
        {
            scanf("%d", &matrix[row][column]);

            if(row == 1 && column == 1)
                min_sum_ending_here[row][column] = matrix[row][column];
            else if(row == 1)
                min_sum_ending_here[row][column] = matrix[row][column] + min_sum_ending_here[row][column - 1];
            else if(column == 1)
                min_sum_ending_here[row][column] = matrix[row][column] + min_sum_ending_here[row - 1][column];
            else
                min_sum_ending_here[row][column] = matrix[row][column] + min(min_sum_ending_here[row - 1][column], min_sum_ending_here[row][column - 1]);
        }
    }

    printf("%lld\n", min_sum_ending_here[order_of_matrix][order_of_matrix]);

    return 0;
}
