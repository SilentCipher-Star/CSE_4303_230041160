#include <iostream>
#include <vector>

using namespace std;
int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> degree(V + 1, 0);
    while (E--)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    int k = degree[1]; // first vertex
    bool regular = true;

    for (int i = 2; i <= V; i++)
    {
        if (degree[i] != k)
        {

            regular = false;
            break;
        }
    }

    if (regular)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}