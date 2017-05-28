#include <stdio.h>

#define SIZE 100001

void push(int stack[], int *top_of_stack,int max_stack[],int *top_of_max_stack,int element)
{
    if(*top_of_stack == -1)
    {
        *top_of_stack = *top_of_max_stack = 0;
        stack[*top_of_stack] = max_stack[*top_of_max_stack] = element;
    }
    else
    {
        *top_of_stack = *top_of_stack + 1;
        stack[*top_of_stack] = element;

        if( (element > max_stack[*top_of_max_stack]) || (*top_of_max_stack == -1) )
        {
            *top_of_max_stack = *top_of_max_stack + 1;
            max_stack[*top_of_max_stack] = element;
        }
    }
}

void pop(int stack[], int *top_of_stack,int max_stack[],int *top_of_max_stack)
{
    if(max_stack[*top_of_max_stack] == stack[*top_of_stack])
    {
        *top_of_max_stack = *top_of_max_stack - 1;
    }

    *top_of_stack = *top_of_stack - 1;
}

int main()
{
    int stack[SIZE], max_stack[SIZE];
    int top_of_stack = -1, top_of_max_stack = -1;
    int i, no_of_queries, query, element;

    scanf("%d", &no_of_queries);

    for(i = 1; i <= no_of_queries; i++)
    {
        scanf("%d", &query);
        switch(query)
        {
            case 1: scanf("%d", &element);
                    push(stack, &top_of_stack, max_stack, &top_of_max_stack, element);
                    break;

            case 2: pop(stack, &top_of_stack, max_stack, &top_of_max_stack);
                    break;

            case 3: printf("%d\n",max_stack[top_of_max_stack]);
        }
    }

    return 0;
}
