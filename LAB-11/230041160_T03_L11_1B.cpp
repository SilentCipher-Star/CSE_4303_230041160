#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int V, E, s;
    cin >> V >> E >> s;

    vector<vector<int>> adj(V + 1); // 1-based indexing
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   //for undirected graph, u to v, v to u
        adj[v].push_back(u);
    }

    //  adjacency list

    cout << "Adjacency list:" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": ";
        for (int v : adj[i])
            cout << v << " ";
        cout << endl;
    }

    // BFS attributes

    vector<string> color(V + 1, "WHITE");  // white -> unvisited
    vector<int> distance(V + 1, -1);      // distance from source
    vector<int> predecessor(V + 1, -1);    // to find parent

    queue<int> q;
    q.push(s);
    color[s] = "GRAY";  //since source has been pushed, hence its processing
    distance[s] = 0;    // distance from itself i.e distance a from a is 0

    vector<int> bfs_order;
    vector<pair<int, int>> bfs_edges;

    while (!q.empty())
    {
        int u = q.front();  //taking vertex u from q
        q.pop();            // to push it to another place, we need to pop from q first
        bfs_order.push_back(u); // adding to bfs_order

        for (int v : adj[u])  // checking the neighbour v of u
        {
            if (color[v] == "WHITE")  // if not visited
            {
                color[v] = "GRAY";   // then visiting
                distance[v] = distance[u] + 1;  
                predecessor[v] = u;
                q.push(v);      
                bfs_edges.push_back({u, v});  // making it part of
            }
        }
        color[u] = "BLACK";
    }

    // BFS order

    cout << "\nBFS order: ";
    for (int u : bfs_order)  // shows the order of vertices being discovered
        cout << u << " ";
    cout << endl;

    // Distances

    cout << "\nDistance from source: " << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << "(" << distance[i] << ") ";   
    }
    cout << endl;

    // Paths

    cout << "\nPaths from source: " << endl;
    for (int i = 1; i <= V; i++)
    {
        if (i == s)
        {
            cout << i << ": " << i << endl;
            continue;
        }
        if (distance[i] == -1){
            continue;
        }
        vector<int> path;
        int x = i;  // to follow predec up to source
        while (x != -1)
        {
            path.push_back(x);  //collecting vecrtices in path order
            x = predecessor[x];
        }
        reverse(path.begin(), path.end()); //to get order from s to i
        cout << i << ": ";
        for (int j = 0; j < path.size(); j++)
        {
            cout << path[j];
            if (j != path.size() - 1)
                cout << "->";
        }
        cout << endl;
    }

    // BFS tree edges

    cout << "\nEdges of BFS tree:" << endl;
    for (auto e : bfs_edges)
        cout << e.first << " " << e.second << endl;

    return 0;
}
