#include <stdio.h>

int main()
{
    int alice[3], bob[3], alice_points = 0, bob_points = 0, i;

    scanf("%d %d %d", &alice[0], &alice[1], &alice[2]);
    scanf("%d %d %d", &bob[0], &bob[1], &bob[2]);

    for(i = 0; i < 3; i++)
    {
        if(alice[i] > bob[i])
            alice_points++;
        if(bob[i] > alice[i])
            bob_points++;
    }

    printf("%d %d\n",alice_points, bob_points);
    return 0;
}
