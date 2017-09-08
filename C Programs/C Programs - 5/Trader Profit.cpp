#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_days, max_transactions;
    scanf("%d %d", &max_transactions, &no_of_days);

    vector <int> price(no_of_days + 1, 0);
    for(int day_i = 1; day_i <= no_of_days; day_i++)
        scanf("%d", &price[day_i]);

    typedef vector <int> v_int;
    vector <v_int> maximum_profit_upto(no_of_days + 1, v_int(max_transactions + 1, 0));

    for(int transaction_i = 1; transaction_i <= max_transactions; transaction_i++)
    {
        for(int day_i = 1; day_i <= no_of_days; day_i++)
        {
            int profit_by_ending_last_trasaction_today = 0;

            for(int starting_day = 1; starting_day < day_i; starting_day++)
            {
                int profit_by_transaction_from_starting_day_ending_today = price[day_i] - price[starting_day]
                                                                        + maximum_profit_upto[starting_day - 1][transaction_i - 1];

                profit_by_ending_last_trasaction_today = max(profit_by_ending_last_trasaction_today,
                                                         profit_by_transaction_from_starting_day_ending_today);
            }

            int profit_by_ending_last_transaction_before_today = maximum_profit_upto[day_i - 1][transaction_i];

            maximum_profit_upto[day_i][transaction_i] = max(profit_by_ending_last_trasaction_today, profit_by_ending_last_transaction_before_today);
        }

    }

    printf("%d\n", maximum_profit_upto[no_of_days][max_transactions]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
