#include <stdio.h>

#define NO_OF_ALPHABETS 26
#define true 1
#define false 0
#define is_alpha(ch) ( (ch >= 'a' && ch <= 'z') ? true : false)
#define lower(ch) (ch < 'a' ? ch + 'a' - 'A' : ch)

int main()
{
    int is_pangram = true, i, alphabet_present[NO_OF_ALPHABETS] = {false};
    char string[1001];
    scanf("%[^\t\n]s", string);

    for(i = 0; string[i] != '\0'; i++)
    {
        if(is_alpha( lower(string[i]) ) )
            alphabet_present[lower(string[i]) - 'a'] = true;
    }

    for(i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(alphabet_present[i] == false)
        {
            is_pangram = false;
            break;
        }
    }

    printf(is_pangram ? "pangram\n" : "not pangram\n");
    return 0;
}
