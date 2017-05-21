#include <stdio.h>
#include <stdlib.h>

long count_miles(int cupcake_calories[], int no_of_cupcakes)
{
    long no_of_miles = 0;
    int i;

    /*Evaluating the polynomial x^{n-1} c_{n-1} + x^{n-2} c_{n-2} + ... + x^1 c_1 + x^0 c_ 0
    with x = 2 and c_i is the calories of the i-th cupcakes
    Horner's method is used.
    P = c_{n-1}
    P = x*c_{n-1} + c_{n-2}
    P = x^2*c{n-1} + x*c{n-2} + c{n-3}

    P = x*P + c_0 ... is the last step.

    We take as many steps as the number of coefficients = n, including the initialisation
    Overall, we do n-1 multiplications of P by x ... So c_{n-1} is multiplied n-1 times, c_{n-2} is multiplied n-2 times and c_0 is multiplied 0 times.
    In general, c_{n - i} appears in step i and then gets multiplied by x (n - i + 1) times, i.e. all steps after i excluding initialisation */
    for(i = 0; i < no_of_cupcakes; i++)
    {
        no_of_miles = (no_of_miles*2 + cupcake_calories[i]);
    }

    return no_of_miles;
}

void selection_sort(int cupcake_calories[], int no_of_cupcakes)
{
    int i, j, smallest, smallest_index;

    //Every iteration finds the i-th minima. So, for n elements, we only need to sort n-1 elements. The last element is forced to be in it's correct position.
    for(i = 0; i < no_of_cupcakes - 1; i++)
    {
        smallest = cupcake_calories[i];
        smallest_index = i;

        for(j = i + 1; j  < no_of_cupcakes; j++)//Go through the list from i to the end to search for a minima
        {
            if(cupcake_calories[j] < smallest)
            {
                smallest = cupcake_calories[j];
                smallest_index = j;
            }
        }

        //Place the i-th minima in the i-th position, and the element at the i-th position where the minima was
        cupcake_calories[smallest_index] = cupcake_calories[i];
        cupcake_calories[i] = smallest;
    }
}

int main()
{
    int cupcake_calories[40], i, no_of_cupcakes;
    long miles;
    scanf("%d",&no_of_cupcakes);

    for(i = 0; i < no_of_cupcakes; i++)
    {
       scanf("%d",&cupcake_calories[i]);
    }

    selection_sort(cupcake_calories, no_of_cupcakes); //Greedy strategy is to eat the lowest calorie cupcake first and the highest last
    miles = count_miles(cupcake_calories, no_of_cupcakes);

    printf("%ld\n",miles);
    return 0;
}


