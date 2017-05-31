#include <stdio.h>
#define MAX_K 101

int main()
{
    int no_of_modulo_k[MAX_K] = {0}, k, current_number, remainder, complement, n, no_of_pairs = 0, i;

    scanf("%d %d", &n, &k);

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &current_number);

        remainder = current_number%k;

        complement = (remainder == 0 ?  0 : (k - remainder) );
        no_of_pairs += no_of_modulo_k[complement];

        no_of_modulo_k[remainder]++;
    }

    printf("%d\n",no_of_pairs);
    return 0;
}
