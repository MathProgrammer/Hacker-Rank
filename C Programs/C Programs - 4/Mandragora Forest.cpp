#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_mandragoras;
    scanf("%d", &no_of_mandragoras);

    vector <int> mandragora_health(no_of_mandragoras + 1, 0);
    for(int i = 1; i <= no_of_mandragoras; i++)
        scanf("%d", &mandragora_health[i]);

    sort(all(mandragora_health));

    vector <long long> sum_of_healths_till(no_of_mandragoras + 1, 0);
    for(int i = 1; i <= no_of_mandragoras; i++)
        sum_of_healths_till[i] = sum_of_healths_till[i - 1] + mandragora_health[i];

    long long maximum_experience = 0;
    for(int defeated_mandragoras = 0; defeated_mandragoras < no_of_mandragoras; defeated_mandragoras++)
    {
        int strength = 1 + defeated_mandragoras;

        long long experience = strength*(sum_of_healths_till[no_of_mandragoras] - sum_of_healths_till[defeated_mandragoras]);

        maximum_experience = max(maximum_experience, experience);
    }

    printf("%lld\n", maximum_experience);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
