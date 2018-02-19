#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;

int check_left(vector <int> &position, vector <int> &height)
{
    int maximum_fall = position[1] + height[1];

    for(int i = 2; i < position.size(); i++)
    {
        if(position[i] > maximum_fall)
            return false;
        else
            maximum_fall = max(maximum_fall, position[i] + height[i]);
    }

    return true;
}

int check_right(vector <int> &position, vector <int> &height)
{
    int no_of_piles = position.size() - 1;

    int maximum_fall = position[no_of_piles] - height[no_of_piles];

    for(int i = no_of_piles - 1; i >= 1; i--)
    {
        if(position[i] < maximum_fall)
            return false;
        else
            maximum_fall = min(maximum_fall, position[i] - height[i]);
    }

    return true;
}

int main()
{
    int no_of_piles;
    cin >> no_of_piles;

    vector<int> position(no_of_piles + 1);
    for(int i = 1; i <= no_of_piles; i++) cin >> position[i];

    vector <int> height(no_of_piles + 1);
    for(int i = 1; i <= no_of_piles; i++) cin >> height[i];

    int left_possible = check_left(position, height);
    int right_possible = check_right(position, height);

    if(left_possible && !right_possible)
        cout <<"LEFT";
    else if(!left_possible && right_possible)
        cout << "RIGHT";
    else
        cout << (left_possible && right_possible ? "BOTH" : "NONE");

    return 0;
}

