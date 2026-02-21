#include<iostream>
#include<vector>
#include<string>
using namespace std;

int time_count = 0;
vector<string>color;
vector<int>discovery;
vector<int>finish_time;
vector<int>predecessor;
vector<int>dfs_order;


void dfs_visit(int u, vector<vector<int>>&adj){
    time_count = time_count+1;
    discovery[u] = time_count;   //marking the curr time when its discovered
    color[u] = "GRAY";
    dfs_order.push_back(u);  //listing order of discovering
    
    for(int v : adj[u]){
        if(color[v] == "WHITE"){
            predecessor[v] = u;
            dfs_visit(v,adj);  //going to the dept of v
        }
    }
    color[u] = "BLACK";
    time_count = time_count+1;
    finish_time[u] = time_count;
    
}

int main(){

    int V, E;
    cin >> V >> E;

    color.assign(V + 1, "WHITE");
    discovery.assign(V + 1, 0);
    finish_time.assign(V + 1, 0);
    predecessor.assign(V + 1, -1);


    vector<vector<int>>adj(V+1);
    vector<pair<int,int>>edges;

    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v) ;
        edges.push_back({u,v});
    }

    for(int i=1; i<=V; i++){
        cout << i << ": ";
        for(int v: adj[i]){
            cout << v << " ";
        }
        cout << endl;
    }

    for(int i =1; i<=V; i++){
        if(color[i] == "WHITE"){
            dfs_visit(i,adj);
        }
    }
    cout << "DFS order: ";
    for(int i =0; i<dfs_order.size(); i++){
        cout << dfs_order[i] << " ";
    }
    cout << endl;

    cout << "Timestamps of Vertex(discovery/finishing): " << endl;
    for(int i =1; i<=V; i++){
        cout << i << "(" << discovery[i] << "/" << finish_time[i] << ")" << endl;

    }

    cout << "\nEdge classification:" << endl;
    for(auto e : edges){
        int u = e.first;
        int v = e.second;

        cout << u << " -> " << v << " : ";

        if (predecessor[v] == u)
        {
            cout << "Tree Edge";
        }
        else if (discovery[v] < discovery[u] && finish_time[u] < finish_time[v])  //v opened b4 u and u closed b4 v
        {
            cout << "Back Edge";
        }
        else if (discovery[u] < discovery[v] && finish_time[v] < finish_time[u])   // u-> v but not as a direct predecessor
        {
            cout << "Forward Edge";
        }
        else
        {
            cout << "Cross Edge";
        }
        cout << endl;
    }
    return 0;
}