#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct info
{
    int x, y, minimum_moves;
};

int is_inside(int x, int y, int n)
{
   return (x >= 0 && x < n && y >= 0 && y < n);
}

int find_minimum_moves_with(int a, int b, int n)
{
    int visited[n][n];
    memset(visited, false, sizeof(visited));

    const int NO_OF_NEIGHBOURS = 8;
    int x_step[] = {a, a, -a, -a, b, b, -b, -b};
    int y_step[] = {b, -b, b, -b, a, -a, a, -a};

    queue <info> Q;
    
    Q.push({0, 0, 0});
    visited[0][0] = true;

    while(!Q.empty())
    {
        info current_square = Q.front(); Q.pop();

        for(int i = 0; i < NO_OF_NEIGHBOURS; i++)
        {
            int neighbour_x = current_square.x + x_step[i];
            int neighbour_y = current_square.y + y_step[i];
            int moves_till_here = current_square.minimum_moves + 1;
            
            if(neighbour_x == n - 1 && neighbour_y == n - 1)
            {
                return moves_till_here;
            }

            if(is_inside(neighbour_x, neighbour_y, n) && !visited[neighbour_x][neighbour_y])
            {
                Q.push({neighbour_x, neighbour_y, moves_till_here});

                visited[neighbour_x][neighbour_y] = true;
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int minimum_moves[n][n];

    for(int a = 1; a < n; a++)
    {
        for(int b = a; b < n; b++)
        {
            minimum_moves[a][b] = find_minimum_moves_with(a, b, n);
            minimum_moves[b][a] = minimum_moves[a][b];
        }
    }

    for(int a = 1; a < n; a++)
    {
        for(int b = 1; b < n; b++)
        {
            printf("%d ", minimum_moves[a][b]);
        }
        printf("\n");
    }

    return 0;
}
