#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int no_of_tickets;
    scanf("%d", &no_of_tickets);

    const int FULL_MASK = (1 << 10) - 1;

    vector <long long> strings_with(FULL_MASK + 1, 0);

    for(int i = 1; i <= no_of_tickets; i++)
    {
        string ticket;
        cin >> ticket;

        int mask = 0;

        for(int j = 0; j < ticket.size(); j++)
        {
            int number = ticket[j] - '0';

            mask |= (1 << number);
        }

        strings_with[mask]++;
    }

    long long no_of_pairs = 0;

    for(int mask_1 = 0; mask_1 <= FULL_MASK; mask_1++)
    {
        for(int mask_2 = mask_1; mask_2 <= FULL_MASK; mask_2++)
        {
            if( (mask_1|mask_2) == FULL_MASK)
            {
                if(mask_1 == mask_2)
                    no_of_pairs += (strings_with[mask_1]*(strings_with[mask_2] - 1) )/2;
                else
                    no_of_pairs += strings_with[mask_1]*strings_with[mask_2];
            }
        }
    }

    printf("%lld\n", no_of_pairs);
    return 0;
}
