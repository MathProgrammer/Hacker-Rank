#include <cstdio>
#include <vector>

using namespace std;


int main()
{
    int no_of_elements, k;
    scanf("%d %d", &no_of_elements, &k);

    vector <int> frequency_mod_k(k + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        frequency_mod_k[element_i%k]++;
    }

    int maximum_subset_size = (frequency_mod_k[0] > 0);
    for(int i = 1; 2*i < k; i++)
    {
        maximum_subset_size += max(frequency_mod_k[i], frequency_mod_k[k - i]);
    }

    if(k%2 == 0)
        maximum_subset_size += (frequency_mod_k[k/2] > 0);

    printf("%d\n", maximum_subset_size);
    return 0;
}

