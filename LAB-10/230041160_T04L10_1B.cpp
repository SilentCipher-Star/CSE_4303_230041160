#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);   
    vector<int> indegree(N, 0);    // Used to find nodes with no dependencies


    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // Storing b as a neighbor of a
        indegree[b]++;       // Increase indegree of b
    }

    queue<int> q;      // stores nodes with indegree = 0
    vector<int> topo; // stores final topological order


    for (int i = 0; i < N; i++){
        if (indegree[i] == 0)   //nodes with 0 indegrees r placed first since they have prerequisites
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();   //taking a node of indegree 0 and adding it to the topological order
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) // All edges u → v are removed
        {
            indegree[v]--;   //hence decreasing the degree of v
            if (indegree[v] == 0)
                q.push(v); // v becomes indegree 0 ,push into queue
        }
    }

    if (topo.size() != N) // if no node ever reaches indegree 0 then the not all nodes are processed
    {
        cout << "[ ]" << endl; 
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << topo[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
