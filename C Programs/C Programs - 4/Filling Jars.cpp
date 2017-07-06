#include <cstdio>

using namespace std;

int main()
{
    int no_of_operations, no_of_jars;
    scanf("%d %d", &no_of_jars, &no_of_operations);

    long long candies = 0;
    int start, end, candies_added;
    while(no_of_operations--)
    {
        scanf("%d %d %d", &start, &end, &candies_added);

        candies += (end - (start - 1) )*1LL*candies_added;
    }

    long long average = candies/no_of_jars;
    printf("%lld\n", average);
}

