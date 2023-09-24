#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1e6 + 5, MAX_L = 22;
int parent[MAX_N][MAX_L];
vector <int> tree[MAX_N];
vector <long long> happiness(MAX_N);
vector <long long> happiness_till(MAX_N);
vector <int> depth(MAX_N, 0);

int is_bit_set(int n, int bit)
{
    return ( (n&(1LL << bit)) != 0 );
}

void dfs(int v, int parent_v = 0)
{
    parent[v][0] = parent_v;

    happiness_till[v] = happiness_till[parent_v] + happiness[v];

    depth[v] = depth[parent_v] + 1;

    for(int child_v : tree[v])
    {
        if(child_v != parent_v)
        {
            dfs(child_v, v);
        }
    }
}

void fill_parents(int n)
{
    for(int l = 1; l < MAX_L; l++)
    {
        for(int v = 1; v <= n; v++)
        {
            int previous_ancestor = parent[v][l - 1];

            parent[v][l] = parent[previous_ancestor][l - 1];
        }
    }
}

int get_ancestor(int v, int length)
{
    for(int l = MAX_L; l >= 0; l--)
    {
        if(is_bit_set(length, l))
        {
            v = parent[v][l];
        }
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_vertices;
    long long initial_happiness;
    cin >> no_of_vertices >> initial_happiness;

    happiness[0] = initial_happiness;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> happiness[i];
    }

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    happiness_till[0] = happiness[0] = initial_happiness;
    depth[0] = -1;
    dfs(1, 0);
    fill_parents(no_of_vertices + 1);

    int no_of_queries;
    cin >> no_of_queries;

    for(int i = 1; i <= no_of_queries; i++)
    {
        int destination;
        long long threshold;
        cin >> threshold >> destination;

        if(happiness_till[destination] < threshold)
        {
            cout << "-1\n";
            continue;
        }

        if(happiness_till[1] >= threshold)
        {
            cout << "1\n";
            continue;
        }

        int left = 0, right = depth[destination];
        while(right - left > 1)
        {
            int mid = (left + right)/2;

            int ancestor = get_ancestor(destination, mid);

            if(happiness_till[ancestor] >= threshold)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        int answer = get_ancestor(destination, left);
        cout << answer << "\n";
    }

    return 0;
}
