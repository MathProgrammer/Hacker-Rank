#include <stdio.h>

int main()
{
    int base, height, area;
    scanf("%d %d", &base, &area);

    height = (area*2)/base;

    height += (base*height < 2*area ? 1 : 0);
    printf("%d\n", height);
    return 0;
}
