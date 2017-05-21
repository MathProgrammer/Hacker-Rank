#include <stdio.h>

int main() {

    int no_of_test_cases, no_of_stones;
    int winner[100], i;

    scanf("%d", &no_of_test_cases);
    winner[1] = 2;
    winner[2] = winner[3] = winner[4] = winner[5] = 1;

    for(i = 6; i <= 100; i++)
    {
        //Player 1 becomes the second player after he makes his move. If any of his moves lead to a configuration winning for Player 2(himself), he makes it
        //Else, he can't avoid losing
        if(winner[i -2] == 2 || winner[i - 3] == 2 || winner[i - 5] == 2)
        {
            winner[i] = 1;
        }
        else
        {
            winner[i] = 2;
        }
    }

    while(no_of_test_cases-- != 0)
    {
        scanf("%d", &no_of_stones);
        printf(winner[no_of_stones] == 1 ? "First\n" : "Second\n");
    }
    return 0;
}

