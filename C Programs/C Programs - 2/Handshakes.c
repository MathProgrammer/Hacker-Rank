#include <stdio.h>

int main()
{
    int no_of_handshakes, no_of_people, no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries-- != 0)
    {
        scanf("%d", &no_of_people);
        no_of_handshakes = (no_of_people*(no_of_people - 1) )/2 ;
        printf("%d\n",no_of_handshakes);
    }
    return 0;
}
