#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 5e5 + 15;
vector <int> graph[MAX_N];
vector <int> component[MAX_N];
vector <int> visited(MAX_N, false);

void dfs(int v, int component_no)
{
    visited[v] = true;
    component[component_no].push_back(v);
    
    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];
        
        if(!visited[child])
            dfs(child, component_no);
    }
}

int main() 
{
    int no_of_vertices, no_of_edges;
    scanf("%d %d", &no_of_vertices, &no_of_edges);
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector <int> component_size;
    
    int no_of_components = 0, deletions = 2;
    long long happiness = 0;
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(!visited[i])
        {
            dfs(i, ++no_of_components);
            component_size.push_back(component[no_of_components].size()); 
            
            int edges = 0;
            for(int j = 0; j < component[no_of_components].size(); j++)
                edges += graph[component[no_of_components][j]].size();
            
            happiness += (component_size.back()*1LL*(component_size.back() - 1));
            
          
           edges /= 2;
            
            if(edges > component_size.back() - 1)
                deletions -= (edges - component_size.back() + 1);
        }
    }
    
    sort(all(component_size));

    if(deletions == 1)
    {   
        for(int i = 0; i < no_of_components && deletions > 0; i++)
        {
            if(component_size[i] >= 2)
                deletions--, happiness -= 2*(component_size[i] - 1);
        }
    }
    
    if(deletions == 2)
    {  
        for(int i = 0; i < no_of_components && deletions > 0; i++)
        {    
            if(component_size[i] == 2 || (component_size[i] >= 2 && deletions == 1) )
                deletions--, happiness -= 2*(component_size[i] - 1);
            else if(component_size[i] > 2)
                deletions = 0, happiness = happiness - (component_size[i] - 1)*1LL*(component_size[i]) + (component_size[i] - 2)*1LL*(component_size[i] - 3);
        }
    }
    
    printf("%lld\n", happiness);
    return 0;
}
