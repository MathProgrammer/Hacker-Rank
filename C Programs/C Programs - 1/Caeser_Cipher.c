#include <stdio.h>

#define NO_OF_ALPHABETS 26
#define true 1
#define false 0
#define is_alpha(ch) ( (ch >= 'a' && ch <= 'z') ? true : false)
#define lower(ch) (ch < 'a' ? ch + 'a' - 'A' : ch)

int main()
{
    int i, key, size_of_string;
    char message[100], first_alphabet;
    scanf("%d", &size_of_string);
    scanf("%s", message);
    scanf("%d",&key);

    for(i = 0; i < size_of_string; i++)
    {
        if( is_alpha(lower(message[i])) )
        {
            first_alphabet = (message[i] >= 'a' && message[i] <= 'z' ? 'a' : 'A');

            message[i] = first_alphabet + (message[i] - first_alphabet + key)%NO_OF_ALPHABETS;
        }
    }

    printf("%s\n",message);
    return 0;
}
