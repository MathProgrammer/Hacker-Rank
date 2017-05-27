#include <stdio.h>

#define true 1
#define false 0
#define isCapital(ch) (ch >= 'A' && ch <= 'Z' ? true : false)

int main()
{
    int i, wordCount = 1;
    char string[100001];
    scanf("%s",string);

    for(i = 0; string[i] != '\0'; i++)
    {
        if(isCapital(string[i]))
            wordCount++;
    }

    printf("%d\n",wordCount);
    return 0;
}
