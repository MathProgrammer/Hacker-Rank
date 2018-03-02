#include <cstdio>

int main()
{
    int x_1, v_1, x_2, v_2;
    scanf("%d %d %d %d", &x_1, &v_1, &x_2, &v_2);

    printf(v_1 > v_2 && (x_1 - x_2)%(v_2 - v_1) == 0 ? "YES\n" : "NO\n");
    return 0;
}
