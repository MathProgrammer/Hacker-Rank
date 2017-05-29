#include <stdio.h>
#define MAX_K 101

int main()
{
    int no_of_modulo_k[MAX_K] = {0}, k, current_number, n, no_of_pairs = 0, i;

    scanf("%d %d", &n, &k);

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &current_number);
        no_of_modulo_k[current_number%k]++;
    }

    no_of_pairs += ( no_of_modulo_k[0]*(no_of_modulo_k[0] - 1 ) )/2;
    for(i = 1 ; i <= k/2 ; i++)
    {
        no_of_pairs +=  (i == k - i ? (no_of_modulo_k[i]*(no_of_modulo_k[i] - 1)/2) : no_of_modulo_k[i]*no_of_modulo_k[k - i]);
    }

    printf("%d\n",no_of_pairs);
    return 0;
}
