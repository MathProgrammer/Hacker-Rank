#include <stdio.h>

#define true 1
#define false 0
#define SIZE 1001

int check_if_balanced()
{
    int balanced = true, open_bracket_stack_top = -1, i;
    char string[SIZE], open_bracket_stack[SIZE];
    scanf("%s", string);

    for(i = 0; string[i] != '\0'; i++)
    {
        switch(string[i])
        {
            case '(' :
            case '[' :
            case '{' :
                       open_bracket_stack[++open_bracket_stack_top] = string[i];
                       break;

            case ')' : if(open_bracket_stack[open_bracket_stack_top] == '(' && open_bracket_stack_top != -1)
                          open_bracket_stack_top--;
                       else
                          return (balanced = false);
                       break;

            case ']' : if(open_bracket_stack[open_bracket_stack_top] == '[' && open_bracket_stack_top != -1)
                          open_bracket_stack_top--;
                       else
                          return (balanced = false);
                       break;

            case '}' : if(open_bracket_stack[open_bracket_stack_top] == '{' && open_bracket_stack_top != -1)
                          open_bracket_stack_top--;
                       else
                            return (balanced = false);
                       break;
        }
    }

    if(open_bracket_stack_top != -1)//Stack should be empty
        balanced = false;

    return balanced;
}

int main()
{
    int no_of_test_cases, balanced;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        balanced = check_if_balanced();
        printf(balanced ? "YES\n" : "NO\n");
    }

    return 0;
}
