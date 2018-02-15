#include <bits/stdc++.h>

using namespace std;

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        string chemical;
        cin >> chemical;

        int n = chemical.size();

        string ending = chemical.substr(n - 2, 2);
        string starting = chemical.substr(0, 5);

        if(ending != "ic")
            printf("not an acid\n");
        else if(n < 4 || starting != "hydro")
            printf("polyatomic acid\n");
        else
            printf("non-metal acid\n");
    }

    return 0;
}

