#include <stdio.h>

#define MAX_LENGTH 2000 + 1
#define true 1
#define false 0

void solve()
{
    char string[MAX_LENGTH];
    int number_of_patterns = 0, i, pattern_i, only_zeroes, atleast_one_zero;
    scanf("%s", string);

    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == '1')
        {
            only_zeroes = true;
            atleast_one_zero = false;

            for(pattern_i = i + 1; string[pattern_i] != '1' && string[pattern_i] != '\0'; pattern_i++)
            {
                if(string[pattern_i] == '0')
                    atleast_one_zero = true;
                else
                    only_zeroes = false;
            }
            i = pattern_i  - 1;

            number_of_patterns += (atleast_one_zero && only_zeroes ? 1 : 0);
        }
    }

    printf("%d\n", number_of_patterns);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
