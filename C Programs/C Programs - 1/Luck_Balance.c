#include <stdio.h>

void selection_sort(int luck_of_important_contests[], int no_of_important_contests)
{
    int i, j, largest, largest_index;

    //Every iteration finds the i-th minima. So, for n elements, we only need to sort n-1 elements. The last element is forced to be in it's correct position.
    for(i = 0; i < no_of_important_contests - 1; i++)
    {
        largest = luck_of_important_contests[i];
        largest_index = i;

        for(j = i + 1; j  < no_of_important_contests; j++)//Go through the list from i to the end to search for a minima
        {
            if(luck_of_important_contests[j] > largest)
            {
                largest = luck_of_important_contests[j];
                largest_index = j;
            }
        }

        //Place the i-th minima in the i-th position, and the element at the i-th position where the minima was
        luck_of_important_contests[largest_index] = luck_of_important_contests[i];
        luck_of_important_contests[i] = largest;
    }
}

int main()
{
   int no_of_contests, no_of_affordable_losses, luck_of_important_contests[100], no_of_important_contests = 0;
   int total_luck = 0, i, importance, luck;

   scanf("%d %d", &no_of_contests, &no_of_affordable_losses);
   for(i = 1; i <= no_of_contests; i++)
   {
       scanf("%d %d", &luck, &importance);

       total_luck += (importance == 0 ? luck : 0); //Lose all unimportant contests.
       if(importance == 1)
       {
           luck_of_important_contests[no_of_important_contests++] = luck;
       }
   }

   selection_sort(luck_of_important_contests, no_of_important_contests); //In descending order

   for(i = 0; i < no_of_important_contests; i++) //Lose as many contests as possible. Choose the k-luckiest contests to lose
   {
       total_luck += (i < no_of_affordable_losses ? luck_of_important_contests[i] : (0 - luck_of_important_contests[i]) );
   }

   printf("%d\n", total_luck);
   return 0;
}
