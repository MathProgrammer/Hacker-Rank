#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);

	while(no_of_test_cases--)
	{
        int jug_1, jug_2, target;
        scanf("%d %d %d", &jug_1, &jug_2, &target);

        printf(target%gcd(jug_1, jug_2) == 0 && target <= max(jug_1, jug_2) ? "YES\n" : "NO\n");
    }

	return 0;
}
