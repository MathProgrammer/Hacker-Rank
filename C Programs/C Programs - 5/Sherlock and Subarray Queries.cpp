#include <cstdio>

#define max(a, b) (a > b ? a : b)

const int MAX_ELEMENTS = 1e5 + 1;
int array[MAX_ELEMENTS];
int maximum[3*MAX_ELEMENTS];
int frequency[3*MAX_ELEMENTS];

void build(int n, int left, int right)
{
    if(left == right)
    {
        maximum[n] = array[left];
        frequency[n] = 1;
        return;
    }

    int mid = (left + right) >> 1;
    build(2*n, left, mid);
    build(2*n + 1, mid + 1, right);

    maximum[n] = max(maximum[2*n], maximum[2*n + 1]);
    if(maximum[2*n] == maximum[2*n + 1])
    {
        frequency[n] = frequency[2*n] + frequency[2*n + 1];
    }
    else
    {
        frequency[n] = (maximum[2*n] > maximum[2*n + 1] ? frequency[2*n] : frequency[2*n + 1]);
    }
}

int get_max(int n, int left, int right, int query_left, int query_right)
{
    if(query_left > right || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
    {
        return maximum[n];
    }

    int mid = (left + right) >> 1;
    int left_max = get_max(2*n, left, mid, query_left, query_right);
    int right_max = get_max(2*n + 1, mid + 1, right, query_left, query_right);

    return max(left_max, right_max);
}

int get_frequency_max(int n, int left, int right, int query_left, int query_right)
{
    if(query_left > right || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
    {
        return frequency[n];
    }

    int mid = (left + right) >> 1;
    int left_max = get_max(2*n, left, mid, query_left, query_right);
    int left_frequency_max  = get_frequency_max(2*n, left, mid, query_left, query_right);

    int right_max = get_max(2*n + 1, mid + 1, right, query_left, query_right);
    int right_frequency_max = get_frequency_max(2*n + 1, mid + 1, right, query_left, query_right);

    if(left_max == right_max)
        return left_frequency_max + right_frequency_max;

    return (left_max > right_max ? left_frequency_max : right_frequency_max);
}

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &array[i]);

    build(1, 1, no_of_elements);

    while(no_of_queries--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        printf("%d\n", get_frequency_max(1, 1, no_of_elements, left, right));
    }

    return 0;
}

