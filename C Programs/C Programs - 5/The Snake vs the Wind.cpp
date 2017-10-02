#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pair_int;

map <pair_int, int> visited;

char get_opposite(char direction)
{
    switch(direction)
    {
        case 'n' : return 's';
        case 's' : return 'n';
        case 'w' : return 'e';
        case 'e' : return 'w';
    }
    return 'x';
}

void get_perpendicular(char &perpendicular_1, char &perpendicular_2, char direction)
{
     switch(direction)
     {
         case 'n' :
         case 's' : perpendicular_1 = 'e', perpendicular_2 = 'w';
                    return;

         case 'e' :
         case 'w' : perpendicular_1 = 'n', perpendicular_2 = 's';
                    return;
     }
}

void move_along(int &x, int &y, char direction)
{
     switch(direction)
     {
         case 'n': x--; return;
         case 's': x++; return;
         case 'e': y++; return;
         case 'w': y--; return;
     }
}

int next_step_legal(int x, int y, char direction, int n)
{
    move_along(x, y, direction);

    return (x >= 0 && x < n && y >= 0 && y < n && !visited[make_pair(x, y)]);
}

void update_position(int &x, int &y, char direction, int n)
{
    char opposite_direction = get_opposite(direction);
    char perpendicular_1, perpendicular_2;
    get_perpendicular(perpendicular_1, perpendicular_2, direction);

    if(next_step_legal(x, y, direction, n))
    {
        move_along(x, y, direction);
        visited[make_pair(x, y)] = true;
    }
    else if(next_step_legal(x, y, perpendicular_1, n))
    {
        move_along(x, y, perpendicular_1);
        visited[make_pair(x, y)] = true;
    }
    else if(next_step_legal(x, y, perpendicular_2, n))
    {
        move_along(x, y, perpendicular_2);
        visited[make_pair(x, y)] = true;
    }
    else
    {
        move_along(x, y, opposite_direction);
        visited[make_pair(x, y)] = true;
    }
}

int main()
{
    int n, snake_x, snake_y;
    char direction;
    scanf("%d %c %d %d", &n, &direction, &snake_x, &snake_y);

    map <pair_int, int> time;
    visited[make_pair(snake_x, snake_y)] = true;

    for(int time_i = 1; time_i <= n*n; time_i++)
    {
        time[make_pair(snake_x, snake_y)] = time_i;
        update_position(snake_x, snake_y, direction, n);
    }

    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            printf("%d ", time[make_pair(x, y)]);
        }
        printf("\n");
    }

    return 0;
}

