#include <stdio.h>

#define NO_OF_ALPHABETS 26

int main()
{
    int i, alphabet_count[NO_OF_ALPHABETS] = {0}, no_of_odd_alphabets = 0;
    char string[10001];
    scanf("%s", string);

    for(i = 0; string[i] != '\0'; i++)
    {
        alphabet_count[string[i] - 'a']++;
    }

    for(i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(alphabet_count[i]%2 == 1)
        {
            no_of_odd_alphabets++;

            if(no_of_odd_alphabets > 1) break; //A palindrome can have odd occurrences of at most 1 character
        }
    }

    printf(no_of_odd_alphabets > 1 ? "NO\n" : "YES\n");
    return 0;
}
