#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

void solve()
{
     int front_i, back_i, is_string_funny = true;
     char text[10001];
     scanf("%s", text);

     for(front_i = 1, back_i = strlen(text) - 1; text[front_i] != '\0' ; front_i++, back_i--)
     {
         if(abs(text[front_i] - text[front_i - 1]) != abs(text[back_i] - text[back_i - 1]) )
         {
             is_string_funny = false;
             break;
         }
      }

     printf(is_string_funny ? "Funny\n" : "Not Funny\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d",&no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
