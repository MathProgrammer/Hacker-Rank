#include <stdio.h>

int main()
{
    int no_of_dishes, skipped_meal, i, current_cost, due_amount = 0, charged_amount;
    scanf("%d %d", &no_of_dishes, &skipped_meal);

    for(i = 0; i < no_of_dishes; i++)
    {
        scanf("%d", &current_cost);

        due_amount += (i != skipped_meal ? current_cost : 0);
    }
    due_amount = due_amount/2;

    scanf("%d", &charged_amount);

    printf(due_amount == charged_amount ? "Bon Appetit\n" : "%d\n",(charged_amount - due_amount));
    return 0;
}
