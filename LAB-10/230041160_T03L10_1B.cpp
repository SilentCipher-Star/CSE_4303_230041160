#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjList(V + 1); // adjList[i] stores all neighbors of vertex i
                                        // Size is V+1 → so we can use 1-based indexing

    vector<vector<int>> adjMatrix(V + 1, vector<int>(V + 1, 0));  //2d matrix

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        adjMatrix[u][v] = 1; // Same edge stored in matrix form
        adjMatrix[v][u] = 1;
    }
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << ":";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}