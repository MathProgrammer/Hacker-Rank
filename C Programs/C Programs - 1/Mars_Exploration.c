#include <stdio.h>

int main()
{
    char message[100];
    int i, no_of_changes = 0;
    scanf("%s",message);

    for(i = 0; message[i] != '\0'; i=i+3)
    {
        if(message[i] != 'S') no_of_changes++;
        if(message[i + 1] != 'O') no_of_changes++;
        if(message[i + 2] != 'S') no_of_changes++;
    }

    printf("%d\n", no_of_changes);
    return 0;
}
