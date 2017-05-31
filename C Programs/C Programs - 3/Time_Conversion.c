#include <stdio.h>

int main()
{
    char time[12];
    scanf("%s", time);
    
    if(time[8] == 'A' && time[0] == '1' && time[1] == '2')
            time[0] = time[1] = '0';
    
    if(time[8] == 'P' && !(time[0] == '1' && time[1] == '2') )
            time[0]++, time[1] += 2;
    
    time[8] = '\0';
    printf("%s\n", time);
    return 0;
}
