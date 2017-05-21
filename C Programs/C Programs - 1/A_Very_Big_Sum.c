#include <stdio.h>

int main(){
    int no_of_numbers, current_number, i ;
    long sum = 0;

    scanf("%d",&no_of_numbers);
    for(i = 0; i < no_of_numbers; i++)
    {
       scanf("%d",&current_number);
       sum = sum + current_number;
    }

    printf("%ld\n", sum);
    return 0;
}
