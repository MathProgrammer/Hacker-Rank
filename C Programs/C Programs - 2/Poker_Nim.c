#include <stdio.h>

int main()
{
    int no_of_test_cases, i, no_of_piles, no_of_stones_in_current_pile, bitwise_XOR_all_piles, no_of_additions;

    scanf("%d",&no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        scanf("%d %d", &no_of_piles, &no_of_additions);

        bitwise_XOR_all_piles = 0;
        for(i = 1; i <= no_of_piles; i++)
        {
            scanf("%d",&no_of_stones_in_current_pile);
            bitwise_XOR_all_piles = bitwise_XOR_all_piles^no_of_stones_in_current_pile;
        }

        printf(bitwise_XOR_all_piles == 0 ? "Second\n" : "First\n"); //The winning strategy is to give your opponent a configuration where the piles XOR to 0
    }
}
