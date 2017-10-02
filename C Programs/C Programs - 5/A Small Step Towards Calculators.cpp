#include <cstdio>

int main()
{
    int x, y;
    char operation;
    scanf("%d%c%d", &x, &operation, &y);

    int answer = (operation == '+' ? x + y : x - y);
    printf("%d\n", answer);

    return 0;
}
