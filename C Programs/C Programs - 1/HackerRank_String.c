#include <stdio.h>

#define true 1
#define false 0
#define lower(ch) ( (ch >= 'A' && ch <= 'Z') ? ch + 'a' - 'A' : ch)

void solve()
{
     int substring_present = false, text_i, substring_i = 0;
     char substring[10] = "Hackerrank", text[10001];
     scanf("%s", text);

     for(text_i = 0; text[text_i] != '\0'; text_i++)
     {
         if(lower(text[text_i]) == lower(substring[substring_i]) )
         {
             substring_i++;
             if(substring_i == 10)
             {
                 substring_present = true;
                 break;
             }
         }
     }

     printf(substring_present ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d",&no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
