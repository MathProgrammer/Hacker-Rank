#include <cstdio>

void print_line(int n)
{
    switch(n)
    {
        case 0: printf("..O.."); return;
        case 1: printf("O.o.O"); return;
        case 2: printf("..O.."); return ;
    }
}

int main()
{
    int no_of_rows, no_of_columns;
    scanf("%d %d", &no_of_rows, &no_of_columns);

    const int ONE_FLOWER_ROWS = 3;

    for(int i = 0; i < ONE_FLOWER_ROWS*no_of_rows; i++)
    {
        for(int j = 1; j <= no_of_columns; j++)
        {
            print_line(i%ONE_FLOWER_ROWS);
        }
        printf("\n");
    }

    return 0;
}
