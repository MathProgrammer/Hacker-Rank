#include <stdio.h>

#define true 1
#define false 0

int isLeapYear(int year)
{
    if(year < 1918 && year%4 == 0)
        return true;
    else if(year > 1918 && (year%400 == 0 || (year%4 == 0 && year%100 != 0)))
        return true;
    else
        return false;
}
int main()
{
    int year;
    scanf("%d", &year);

    if(year == 1918)
        printf("26.09.1918\n");
    else if(isLeapYear(year))
        printf("12.09.%d\n",year);
    else
        printf("13.09.%d\n",year);

    return 0;
}
