#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define max(a, b) (a > b ? a : b)

int main()
{
    int front_i, back_i, no_of_changes = 0;
    int no_of_characters, maximum_changes;
    scanf("%d %d", &no_of_characters, &maximum_changes);

    char *check = malloc( (no_of_characters + 1)*sizeof(char));
    int *already_changed = malloc(no_of_characters*sizeof(int));
    scanf("%s", check);

    //Make check a palindrome
    for(front_i = 0, back_i = no_of_characters - 1; front_i <= back_i ; front_i++, back_i--)
    {
         *(already_changed + front_i) = *(already_changed + back_i) = false;

        if( *(check + front_i) != *(check + back_i))
        {
            *(check + front_i) = *(check + back_i) = max( *(check + front_i), *(check + back_i));

            *(already_changed + front_i) = *(already_changed + back_i) = true;
            no_of_changes++;
        }
    }

    //Maximise the palindrome
    for(front_i = 0, back_i = no_of_characters - 1; (front_i <= back_i) && (no_of_changes < maximum_changes); front_i++, back_i--)
    {
        if( (front_i == back_i) && ( *(check + front_i) != '9') )
        {
            *(check + front_i) = '9';
            no_of_changes++;
        }
        //If we have to change both digits of a pair, then check if we can perform 2 more changes
        else if(*(check + front_i) != '9' && !( *(already_changed + front_i) == false && (no_of_changes + 2 > maximum_changes) ) )
        {
            *(check + front_i) =  *(check + back_i) = '9';
            no_of_changes += (*(already_changed + front_i)  ? 1 : 2);
        }
    }

    printf(no_of_changes > maximum_changes ? "-1\n" : "%s\n",check);

    free(already_changed);
    free(check);
    return 0;
}
